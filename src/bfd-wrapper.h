#include <bfd.h>

#define declare_getter(typename, pfx, name) \
    bfd_##pfx##_##name(typename self)

const char *declare_getter(struct bfd *, h, filename);

const struct bfd_target *declare_getter(struct bfd *, h, xvec);

void *declare_getter(struct bfd *, h, iostream);

const struct bfd_iovec *declare_getter(struct bfd *, h, iovec);

struct bfd *declare_getter(struct bfd *, h, lru_prev);
struct bfd *declare_getter(struct bfd *, h, lru_next);

ufile_ptr declare_getter(struct bfd *, h, where);

long declare_getter(struct bfd *, h, mtime);

unsigned int declare_getter(struct bfd *, h, id);

flagword declare_getter(struct bfd *, h, flags);

ENUM_BITFIELD(bfd_format)
declare_getter(struct bfd *, h, format);

ENUM_BITFIELD(bfd_direction)
declare_getter(struct bfd *, h, direction);

ENUM_BITFIELD(bfd_last_io)
declare_getter(struct bfd *, h, last_io);

unsigned int declare_getter(struct bfd *, h, cacheable);

unsigned int declare_getter(struct bfd *, h, target_defaulted);

unsigned int declare_getter(struct bfd *, h, opened_once);

unsigned int declare_getter(struct bfd *, h, mtime_set);

unsigned int declare_getter(struct bfd *, h, no_export);

unsigned int declare_getter(struct bfd *, h, output_has_begun);

unsigned int declare_getter(struct bfd *, h, has_armap);

unsigned int declare_getter(struct bfd *, h, is_thin_archive);

unsigned int declare_getter(struct bfd *, h, no_element_cache);

unsigned int declare_getter(struct bfd *, h, selective_search);

unsigned int declare_getter(struct bfd *, h, is_linker_output);

unsigned int declare_getter(struct bfd *, h, is_linker_input);

ENUM_BITFIELD(bfd_plugin_format)
declare_getter(struct bfd *, h, plugin_format);

unsigned int declare_getter(struct bfd *, h, lto_output);

unsigned int declare_getter(struct bfd *, h, lto_slim_object);

unsigned int declare_getter(struct bfd *, h, read_only);

bfd *declare_getter(struct bfd *, h, plugin_dummy_bfd);

ufile_ptr declare_getter(struct bfd *, h, origin);

ufile_ptr declare_getter(struct bfd *, h, proxy_origin);

struct bfd_hash_table declare_getter(struct bfd *, h, section_htab);

struct bfd_section *declare_getter(struct bfd *, h, sections);

struct bfd_section *declare_getter(struct bfd *, h, section_last);

unsigned int declare_getter(struct bfd *, h, section_count);

int declare_getter(struct bfd *, h, archive_plugin_fd);

unsigned int declare_getter(struct bfd *, h, archive_plugin_fd_open_count);

int declare_getter(struct bfd *, h, archive_pass);

bfd_size_type declare_getter(struct bfd *, h, alloc_size);

bfd_vma declare_getter(struct bfd *, h, start_address);

struct bfd_symbol **declare_getter(struct bfd *, h, outsymbols);

unsigned int declare_getter(struct bfd *, h, symcount);

unsigned int declare_getter(struct bfd *, h, dynsymcount);

const struct bfd_arch_info *declare_getter(struct bfd *, h, arch_info);

ufile_ptr declare_getter(struct bfd *, h, size);

void *declare_getter(struct bfd *, h, arelt_data);
struct bfd *declare_getter(struct bfd *, h, my_archive);
struct bfd *declare_getter(struct bfd *, h, archive_next);
struct bfd *declare_getter(struct bfd *, h, archive_head);
struct bfd *declare_getter(struct bfd *, h, nested_archives);

struct bfd *declare_getter(struct bfd *, h, link_next);
struct bfd *declare_getter(struct bfd *, h, link_hash);

void *declare_getter(struct bfd *, h, usrdata);

void *declare_getter(struct bfd *, h, memory);

const struct bfd_build_id *declare_getter(struct bfd *, h, build_id);

// -----------------------------------------------------

const char *declare_getter(struct bfd_section *, sec, name);

struct bfd_section *declare_getter(struct bfd_section *, sec, next);

struct bfd_section *declare_getter(struct bfd_section *, sec, prev);

unsigned int declare_getter(struct bfd_section *, sec, section_id);

unsigned int declare_getter(struct bfd_section *, sec, index);

flagword declare_getter(struct bfd_section *, sec, flags);

unsigned int declare_getter(struct bfd_section *, sec, user_set_vma);

unsigned int declare_getter(struct bfd_section *, sec, linker_mark);

unsigned int declare_getter(struct bfd_section *, sec, linker_has_input);

unsigned int declare_getter(struct bfd_section *, sec, gc_mark);

unsigned int declare_getter(struct bfd_section *, sec, compress_status);

unsigned int declare_getter(struct bfd_section *, sec, segment_mark);

unsigned int declare_getter(struct bfd_section *, sec, sec_info_type);

unsigned int declare_getter(struct bfd_section *, sec, use_rela_p);

unsigned int declare_getter(struct bfd_section *, sec, sec_flg0);

unsigned int declare_getter(struct bfd_section *, sec, sec_flg1);

unsigned int declare_getter(struct bfd_section *, sec, sec_flg2);

unsigned int declare_getter(struct bfd_section *, sec, sec_flg3);

unsigned int declare_getter(struct bfd_section *, sec, sec_flg4);

unsigned int declare_getter(struct bfd_section *, sec, sec_flg5);

bfd_vma declare_getter(struct bfd_section *, sec, vma);

bfd_vma declare_getter(struct bfd_section *, sec, lma);

bfd_size_type declare_getter(struct bfd_section *, sec, size);

bfd_size_type declare_getter(struct bfd_section *, sec, rawsize);

bfd_size_type declare_getter(struct bfd_section *, sec, compressed_size);

bfd_vma declare_getter(struct bfd_section *, sec, output_offset);

struct bfd_section *declare_getter(struct bfd_section *, sec, output_section);

struct reloc_cache_entry *declare_getter(struct bfd_section *, sec, relocation);

struct reloc_cache_entry **declare_getter(struct bfd_section *, sec, orelocation);

unsigned declare_getter(struct bfd_section *, sec, reloc_count);

unsigned int declare_getter(struct bfd_section *, sec, alignment_power);

file_ptr declare_getter(struct bfd_section *, sec, filepos);

file_ptr declare_getter(struct bfd_section *, sec, rel_filepos);

file_ptr declare_getter(struct bfd_section *, sec, line_filepos);

void *declare_getter(struct bfd_section *, sec, userdata);

bfd_byte *declare_getter(struct bfd_section *, sec, contents);

alent *declare_getter(struct bfd_section *, sec, lineno);

unsigned int declare_getter(struct bfd_section *, sec, lineno_count);

unsigned int declare_getter(struct bfd_section *, sec, entsize);

struct bfd_section *declare_getter(struct bfd_section *, sec, kept_section);

file_ptr declare_getter(struct bfd_section *, sec, moving_line_filepos);

int declare_getter(struct bfd_section *, sec, target_index);

void *declare_getter(struct bfd_section *, sec, used_by_bfd);

struct relent_chain *declare_getter(struct bfd_section *, sec, constructor_chain);

bfd *declare_getter(struct bfd_section *, sec, owner);

struct bfd_symbol *declare_getter(struct bfd_section *, sec, symbol);

struct bfd_symbol **declare_getter(struct bfd_section *, sec, symbol_ptr_ptr);

// TODO:
//   union {
//     struct bfd_link_order *link_order;
//     struct bfd_section *s;
//     const char *linked_to_symbol_name;
//   } map_head, map_tail;

struct bfd_section *declare_getter(struct bfd_section *, sec, already_assigned);

unsigned int declare_getter(struct bfd_section *, sec, type);

// -------------------------------------------------------------------

struct bfd_hash_entry **declare_getter(struct bfd_hash_table*, ht, table);

void *declare_getter(struct bfd_hash_table*, ht, memory);

unsigned int declare_getter(struct bfd_hash_table*, ht, size);

unsigned int declare_getter(struct bfd_hash_table*, ht, count);

unsigned int declare_getter(struct bfd_hash_table*, ht, entsize);

unsigned int declare_getter(struct bfd_hash_table*, ht, frozen);
