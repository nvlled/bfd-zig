
#include <bfd.h>

#define extrn extern inline

#define define_getter(typename, pfx, name) \
    bfd_##pfx##_##name(typename self)      \
    {                                      \
        return self->name;                 \
    }

#define define_getter_expr(typename, pfx, name, expr) \
    bfd_##pfx##_##name(typename self)                 \
    {                                                 \
        return self->expr;                            \
    }


extrn const char *define_getter(struct bfd *, h, filename);

extrn const struct bfd_target *define_getter(struct bfd *, h, xvec);

extrn void *define_getter(struct bfd *, h, iostream);

extrn const struct bfd_iovec *define_getter(struct bfd *, h, iovec);

extrn struct bfd *define_getter(struct bfd *, h, lru_prev);
extrn struct bfd *define_getter(struct bfd *, h, lru_next);

extrn ufile_ptr define_getter(struct bfd *, h, where);

extrn long define_getter(struct bfd *, h, mtime);

extrn unsigned int define_getter(struct bfd *, h, id);

extrn flagword define_getter(struct bfd *, h, flags);

ENUM_BITFIELD(bfd_format)
extrn define_getter(struct bfd *, h, format);

ENUM_BITFIELD(bfd_direction)
extrn define_getter(struct bfd *, h, direction);

ENUM_BITFIELD(bfd_last_io)
extrn define_getter(struct bfd *, h, last_io);

extrn unsigned int define_getter(struct bfd *, h, cacheable);

extrn unsigned int define_getter(struct bfd *, h, target_defaulted);

extrn unsigned int define_getter(struct bfd *, h, opened_once);

extrn unsigned int define_getter(struct bfd *, h, mtime_set);

extrn unsigned int define_getter(struct bfd *, h, no_export);

extrn unsigned int define_getter(struct bfd *, h, output_has_begun);

extrn unsigned int define_getter(struct bfd *, h, has_armap);

extrn unsigned int define_getter(struct bfd *, h, is_thin_archive);

extrn unsigned int define_getter(struct bfd *, h, no_element_cache);

extrn unsigned int define_getter(struct bfd *, h, selective_search);

extrn unsigned int define_getter(struct bfd *, h, is_linker_output);

extrn unsigned int define_getter(struct bfd *, h, is_linker_input);

ENUM_BITFIELD(bfd_plugin_format)
extrn define_getter(struct bfd *, h, plugin_format);

extrn unsigned int define_getter(struct bfd *, h, lto_output);

extrn unsigned int define_getter(struct bfd *, h, lto_slim_object);

extrn unsigned int define_getter(struct bfd *, h, read_only);

extrn bfd *define_getter(struct bfd *, h, plugin_dummy_bfd);

extrn ufile_ptr define_getter(struct bfd *, h, origin);

extrn ufile_ptr define_getter(struct bfd *, h, proxy_origin);

extrn struct bfd_hash_table define_getter(struct bfd *, h, section_htab);

extrn struct bfd_section *define_getter(struct bfd *, h, sections);

extrn struct bfd_section *define_getter(struct bfd *, h, section_last);

extrn unsigned int define_getter(struct bfd *, h, section_count);

extrn int define_getter(struct bfd *, h, archive_plugin_fd);

extrn unsigned int define_getter(struct bfd *, h, archive_plugin_fd_open_count);

extrn int define_getter(struct bfd *, h, archive_pass);

extrn bfd_size_type define_getter(struct bfd *, h, alloc_size);

extrn bfd_vma define_getter(struct bfd *, h, start_address);

extrn struct bfd_symbol **define_getter(struct bfd *, h, outsymbols);

extrn unsigned int define_getter(struct bfd *, h, symcount);

extrn unsigned int define_getter(struct bfd *, h, dynsymcount);

extrn const struct bfd_arch_info *define_getter(struct bfd *, h, arch_info);

extrn ufile_ptr define_getter(struct bfd *, h, size);

extrn void *define_getter(struct bfd *, h, arelt_data);
extrn struct bfd *define_getter(struct bfd *, h, my_archive);
extrn struct bfd *define_getter(struct bfd *, h, archive_next);
extrn struct bfd *define_getter(struct bfd *, h, archive_head);
extrn struct bfd *define_getter(struct bfd *, h, nested_archives);

extrn struct bfd *define_getter_expr(struct bfd *, h, link_next, link.next);

extrn struct bfd_link_hash_table *
define_getter_expr(struct bfd *, h, link_hash, link.hash);

extrn void *define_getter(struct bfd *, h, usrdata);

extrn void *define_getter(struct bfd *, h, memory);

extrn const struct bfd_build_id *define_getter(struct bfd *, h, build_id);

// -----------------------------------------------------

extrn const char *define_getter(struct bfd_section *, sec, name);

extrn struct bfd_section *define_getter(struct bfd_section *, sec, next);

extrn struct bfd_section *define_getter(struct bfd_section *, sec, prev);

extrn unsigned int define_getter(struct bfd_section *, sec, section_id);

extrn unsigned int define_getter(struct bfd_section *, sec, index);

extrn flagword define_getter(struct bfd_section *, sec, flags);

extrn unsigned int define_getter(struct bfd_section *, sec, user_set_vma);

extrn unsigned int define_getter(struct bfd_section *, sec, linker_mark);

extrn unsigned int define_getter(struct bfd_section *, sec, linker_has_input);

extrn unsigned int define_getter(struct bfd_section *, sec, gc_mark);

extrn unsigned int define_getter(struct bfd_section *, sec, compress_status);

extrn unsigned int define_getter(struct bfd_section *, sec, segment_mark);

extrn unsigned int define_getter(struct bfd_section *, sec, sec_info_type);

extrn unsigned int define_getter(struct bfd_section *, sec, use_rela_p);

extrn unsigned int define_getter(struct bfd_section *, sec, sec_flg0);

extrn unsigned int define_getter(struct bfd_section *, sec, sec_flg1);

extrn unsigned int define_getter(struct bfd_section *, sec, sec_flg2);

extrn unsigned int define_getter(struct bfd_section *, sec, sec_flg3);

extrn unsigned int define_getter(struct bfd_section *, sec, sec_flg4);

extrn unsigned int define_getter(struct bfd_section *, sec, sec_flg5);

extrn bfd_vma define_getter(struct bfd_section *, sec, vma);

extrn bfd_vma define_getter(struct bfd_section *, sec, lma);

extrn bfd_size_type define_getter(struct bfd_section *, sec, size);

extrn bfd_size_type define_getter(struct bfd_section *, sec, rawsize);

extrn bfd_size_type define_getter(struct bfd_section *, sec, compressed_size);

extrn bfd_vma define_getter(struct bfd_section *, sec, output_offset);

extrn struct bfd_section *define_getter(struct bfd_section *, sec, output_section);

extrn struct reloc_cache_entry *define_getter(struct bfd_section *, sec, relocation);

extrn struct reloc_cache_entry **define_getter(struct bfd_section *, sec, orelocation);

extrn unsigned define_getter(struct bfd_section *, sec, reloc_count);

extrn unsigned int define_getter(struct bfd_section *, sec, alignment_power);

extrn file_ptr define_getter(struct bfd_section *, sec, filepos);

extrn file_ptr define_getter(struct bfd_section *, sec, rel_filepos);

extrn file_ptr define_getter(struct bfd_section *, sec, line_filepos);

extrn void *define_getter(struct bfd_section *, sec, userdata);

extrn bfd_byte *define_getter(struct bfd_section *, sec, contents);

extrn alent *define_getter(struct bfd_section *, sec, lineno);

extrn unsigned int define_getter(struct bfd_section *, sec, lineno_count);

extrn unsigned int define_getter(struct bfd_section *, sec, entsize);

extrn struct bfd_section *define_getter(struct bfd_section *, sec, kept_section);

extrn file_ptr define_getter(struct bfd_section *, sec, moving_line_filepos);

extrn int define_getter(struct bfd_section *, sec, target_index);

extrn void *define_getter(struct bfd_section *, sec, used_by_bfd);

extrn struct relent_chain *define_getter(struct bfd_section *, sec, constructor_chain);

extrn bfd *define_getter(struct bfd_section *, sec, owner);

extrn struct bfd_symbol *define_getter(struct bfd_section *, sec, symbol);

extrn struct bfd_symbol **define_getter(struct bfd_section *, sec, symbol_ptr_ptr);

extrn struct bfd_link_order *
define_getter_expr(struct bfd_section *, sec, map_head_link_order, map_head.link_order);

extrn struct bfd_section *
define_getter_expr(struct bfd_section *, sec, map_head_s, map_head.s);

extrn const char *
define_getter_expr(struct bfd_section *, sec, map_head_linked_to_symbol_name, map_head.linked_to_symbol_name);

extrn struct bfd_link_order *
define_getter_expr(struct bfd_section *, sec, map_tail_link_order, map_tail.link_order);

extrn struct bfd_section *
define_getter_expr(struct bfd_section *, sec, map_tail_s, map_tail.s);

extrn const char *
define_getter_expr(struct bfd_section *, sec, map_tail_linked_to_symbol_name, map_tail.linked_to_symbol_name);

extrn struct bfd_section *define_getter(struct bfd_section *, sec, already_assigned);

extrn unsigned int define_getter(struct bfd_section *, sec, type);

// -------------------------------------------------------------------

extrn struct bfd_hash_entry **define_getter(struct bfd_hash_table *, ht, table);

extrn void *define_getter(struct bfd_hash_table *, ht, memory);

extrn unsigned int define_getter(struct bfd_hash_table *, ht, size);

extrn unsigned int define_getter(struct bfd_hash_table *, ht, count);

extrn unsigned int define_getter(struct bfd_hash_table *, ht, entsize);

extrn unsigned int define_getter(struct bfd_hash_table *, ht, frozen);

// -------------------------------------------------------------------

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, type);

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, size);

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, bitsize);

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, rightshift);

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, bitpos);

ENUM_BITFIELD(complain_overflow)
extrn define_getter(struct reloc_howto_struct *, rh, complain_on_overflow);

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, negate);

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, pc_relative);

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, partial_inplace);

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, pcrel_offset);

extrn unsigned int define_getter(struct reloc_howto_struct *, rh, install_addend);

extrn bfd_vma define_getter(struct reloc_howto_struct *, rh, src_mask);

extrn bfd_vma define_getter(struct reloc_howto_struct *, rh, dst_mask);
