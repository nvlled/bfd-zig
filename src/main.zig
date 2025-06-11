const std = @import("std");
const bfd = @import("bfd_zig");
const stdout = std.io.getStdOut().writer();

// TODO: read how to automatically build object files with zig build
// TODO: try using this project as a dependency on another project

pub fn main() !void {
    const handle = bfd.bfd_openr("a.out", null);
    if (handle == null) {
        return error.BfdOpenFileError;
    }
    if (!bfd.bfd_check_format(handle, bfd.bfd_object)) {
        return error.BfdNotAnExe;
    }

    try stdout.print("filename: {s}\n", .{bfd.bfd_h_filename(handle)});
    // try stdout.print("flavor: {d}\n", .{c.bfd_h_xvec(handle).?.*.flavour});
    try stdout.print("xvec: {any}\n", .{bfd.bfd_h_xvec(handle)});
    try stdout.print("iostream: {any}\n", .{bfd.bfd_h_iostream(handle)});
    try stdout.print("mtime: {any}\n", .{bfd.bfd_h_mtime(handle)});
    try stdout.print("format: {any}\n", .{bfd.bfd_h_format(handle)});
}
