
# bfd_zig

A WIP zig wrapper for [libbfd](https://ftp.gnu.org/pub/old-gnu/Manuals/bfd-2.9.1/html_chapter/bfd_toc.html).

## Purpose and reasoning
- I'm reading the book "Practical Binary Analysis", and that book uses libbfd
- The book uses C++ to interface with libbfd, but I thought it was a good chance to try out and learn zig since I heard it has a good C interop (libbfd is written in C)
- libbfd extensively uses C bitfields, but AFAIU zig currently doesn't [support bit fields when translating C](https://github.com/ziglang/zig/issues/1499)
- What happens is that when structs contain bitfields it becomes opaque, meaning the fields could not be accessed from zig, which makes libbfd unusable
- This wrapper is a workaround for zig's issue with translating C bit fields

## Implementation notes 
I used inline getters function for each fields of the struct that contains a bit field. I've thought of other options, such as:

- Cast the struct in a plain []u8, then painfully access each field by slicing and casting
- Manually modify the bfd.h so that bitfields are converted into plain int fields.

At least with getter functions, it's still some work, but it's a fairly mechanical process, that could be done with a source parser/generator if ever I feel like doing that too.

## Usage
The bfd structs that contain bitfields are: bfd, bfd_section, bfd_hash_table. Accessing from zig would be done as follows:
```zig
const c = @import("bfd_zig");
pub fn main() void {
    const handle: *c.bfd = c.bfd_openr("blah.exe", null);
    if (handle == null) {
        return error.BfdOpenFileError;
    }

    // Since bfd has bitfields, c.bfd is opaque and handle->filename cannot be
    // accessed directly from zig. Here, c.bfd_h_filename is the getter function
    // that is used instead:
    try stdout.print("filename: {s}\n", .{c.bfd_h_filename(handle)});
}
```

The getter function mapping is as follows:
- for bfd: handle.      handle.$FIELD -> c.bfd_h_$FIELD(handle)
- for bfd_section:      sec.$FIELD -> c.bfd_sec_$FIELD(sec)
- for bfd_hash_table:   ht.$FIELD -> c.bfd_ht_$FIELD(ht)

For example:
-  filename  -> c.bfd_h_filename(handle)
-  sec.next  -> c.bfd_sec_next(sec)
-  ht.memory -> c.bfd_ht_memory(ht)