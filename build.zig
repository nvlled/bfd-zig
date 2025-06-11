const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const mod = b.addTranslateC(.{
        .root_source_file = b.path("src/bfd-wrapper.h"),
        .target = target,
        .optimize = optimize,
        .link_libc = true,
    }).createModule();

    mod.linkSystemLibrary("bfd", .{});
    mod.addIncludePath(b.path("src"));
    mod.addCSourceFile(.{
        .file = b.path("src/bfd-wrapper.c"),
        .language = .c,
    });
    mod.addCSourceFile(.{
        .file = b.path("src/bfd-mod.c"),
        .language = .c,
    });

    const exe = b.addExecutable(.{
        .name = "bfd_zig",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .root_source_file = b.path("src/main.zig"),
            .imports = &.{.{
                .name = "bfd_zig",
                .module = mod,
            }},
        }),
    });
    exe.linkLibC();
    mod.addIncludePath(b.path("src"));
    b.installArtifact(exe);

    // export module so it can be imported on other projects
    b.modules.put("bfd_zig", mod) catch @panic("oof");

    const mod_tests = b.addTest(.{
        .root_module = mod,
    });

    const run_mod_tests = b.addRunArtifact(mod_tests);

    const test_step = b.step("test", "Run tests");
    test_step.dependOn(&run_mod_tests.step);
}
