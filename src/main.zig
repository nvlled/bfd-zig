const std = @import("std");
const c = @import("bfd_zig");
const stdout = std.io.getStdOut().writer();

pub fn main() !void {
    const handle = c.bfd_openr("a.out", null);
    if (handle == null) {
        return error.BfdOpenFileError;
    }
    if (!c.bfd_check_format(handle, c.bfd_object)) {
        return error.BfdNotAnExe;
    }

    try stdout.print("filename: {s}\n", .{c.bfd_h_filename(handle)});
    try stdout.print("mtime: {d}\n", .{c.bfd_h_mtime(handle)});

    const flavour = c.bfd_get_flavour(handle);
    const flavour_text = switch (flavour) {
        else => "unknown",
        c.bfd_target_unknown_flavour => "unknown",
        c.bfd_target_aout_flavour => "aout",
        c.bfd_target_coff_flavour => "coff",
        c.bfd_target_ecoff_flavour => "ecoff",
        c.bfd_target_xcoff_flavour => "xcoff",
        c.bfd_target_elf_flavour => "elf",
        c.bfd_target_tekhex_flavour => "tekhex",
        c.bfd_target_srec_flavour => "srec",
        c.bfd_target_verilog_flavour => "verilog",
        c.bfd_target_ihex_flavour => "ihex",
        c.bfd_target_som_flavour => "som",
        c.bfd_target_msdos_flavour => "msdos",
        c.bfd_target_evax_flavour => "evax",
        c.bfd_target_mmo_flavour => "mmo",
        c.bfd_target_mach_o_flavour => "mach",
        c.bfd_target_pef_flavour => "pef",
        c.bfd_target_pef_xlib_flavour => "pef",
        c.bfd_target_sym_flavour => "sym",
    };
    try stdout.print("flavour: {s}\n", .{flavour_text});
}
