#include "bfd-mod.h"
#define extrn extern inline

extrn const char *
bfd_section_name(const asection *sec)
{
    return sec->name;
}

extrn bfd_size_type
bfd_section_size(const asection *sec)
{
    return sec->size;
}

extrn bfd_vma
bfd_section_vma(const asection *sec)
{
    return sec->vma;
}

extrn bfd_vma
bfd_section_lma(const asection *sec)
{
    return sec->lma;
}

extrn unsigned int
bfd_section_alignment(const asection *sec)
{
    return sec->alignment_power;
}

extrn flagword
bfd_section_flags(const asection *sec)
{
    return sec->flags;
}

extrn void *
bfd_section_userdata(const asection *sec)
{
    return sec->userdata;
}
extrn bool
bfd_is_com_section(const asection *sec)
{
    ;
    return (sec->flags & SEC_IS_COMMON) != 0;
}

extrn bool
bfd_set_section_userdata(asection *sec, void *val)
{
    sec->userdata = val;
    return true;
}

extrn bool
bfd_set_section_vma(asection *sec, bfd_vma val)
{
    sec->vma = sec->lma = val;
    sec->user_set_vma = true;
    return true;
}

extrn bool
bfd_set_section_lma(asection *sec, bfd_vma val)
{
    sec->lma = val;
    return true;
}

extrn bool
bfd_set_section_alignment(asection *sec, unsigned int val)
{
    if (val >= sizeof(bfd_vma) * 8 - 1)
        return false;
    sec->alignment_power = val;
    return true;
}  

extrn bool
bfd_is_und_section (const asection *sec)
{
  return sec == bfd_und_section_ptr;
}

extrn bool
bfd_is_abs_section (const asection *sec)
{
  return sec == bfd_abs_section_ptr;
}

extrn bool
bfd_is_ind_section (const asection *sec)
{
  return sec == bfd_ind_section_ptr;
}

extrn bool
bfd_is_const_section (const asection *sec)
{
  return (sec >= _bfd_std_section
	  && sec < _bfd_std_section + (sizeof (_bfd_std_section)
				       / sizeof (_bfd_std_section[0])));
}

/* Return TRUE if input section SEC has been discarded.  */
extrn bool
discarded_section (const asection *sec)
{
  return (!bfd_is_abs_section (sec)
	  && bfd_is_abs_section (sec->output_section)
	  && sec->sec_info_type != SEC_INFO_TYPE_MERGE
	  && sec->sec_info_type != SEC_INFO_TYPE_JUST_SYMS);
}

extrn const char *
bfd_get_filename (const bfd *abfd)
{
  return abfd->filename;
}

extrn bool
bfd_get_cacheable (const bfd *abfd)
{
  return abfd->cacheable;
}

extrn enum bfd_format
bfd_get_format (const bfd *abfd)
{
  return abfd->format;
}

extrn flagword
bfd_get_file_flags (const bfd *abfd)
{
  return abfd->flags;
}

extrn bfd_vma
bfd_get_start_address (const bfd *abfd)
{
  return abfd->start_address;
}

extrn unsigned int
bfd_get_symcount (const bfd *abfd)
{
  return abfd->symcount;
}

extrn unsigned int
bfd_get_dynamic_symcount (const bfd *abfd)
{
  return abfd->dynsymcount;
}

extrn struct bfd_symbol **
bfd_get_outsymbols (const bfd *abfd)
{
  return abfd->outsymbols;
}

extrn unsigned int
bfd_count_sections (const bfd *abfd)
{
  return abfd->section_count;
}

extrn bool
bfd_has_map (const bfd *abfd)
{
  return abfd->has_armap;
}

extrn bool
bfd_is_thin_archive (const bfd *abfd)
{
  return abfd->is_thin_archive;
}

extrn void *
bfd_usrdata (const bfd *abfd)
{
  return abfd->usrdata;
}

/* See note beside bfd_set_section_userdata.  */
extrn bool
bfd_set_cacheable (bfd * abfd, bool val)
{
  abfd->cacheable = val;
  return true;
}

extrn void
bfd_set_thin_archive (bfd *abfd, bool val)
{
  abfd->is_thin_archive = val;
}

extrn void
bfd_set_usrdata (bfd *abfd, void *val)
{
  abfd->usrdata = val;
}

extrn asection *
bfd_asymbol_section (const asymbol *sy)
{
  return sy->section;
}

extrn bfd_vma
bfd_asymbol_value (const asymbol *sy)
{
  return sy->section->vma + sy->value;
}

extrn const char *
bfd_asymbol_name (const asymbol *sy)
{
  return sy->name;
}

extrn struct bfd *
bfd_asymbol_bfd (const asymbol *sy)
{
  return sy->the_bfd;
}

extrn void
bfd_set_asymbol_name (asymbol *sy, const char *name)
{
  sy->name = name;
}

extrn bfd_size_type
bfd_get_section_limit_octets (const bfd *abfd, const asection *sec)
{
  if (abfd->direction != write_direction && sec->rawsize != 0)
    return sec->rawsize;
  return sec->size;
}

extrn bfd_size_type
bfd_get_section_limit (const bfd *abfd, const asection *sec)
{
  return (bfd_get_section_limit_octets (abfd, sec)
	  / bfd_octets_per_byte (abfd, sec));
}

extrn bfd_size_type
bfd_get_section_alloc_size (const bfd *abfd, const asection *sec)
{
  if (abfd->direction != write_direction && sec->rawsize > sec->size)
    return sec->rawsize;
  return sec->size;
}

extrn void
bfd_section_list_remove (bfd *abfd, asection *s)
{
  asection *next = s->next;
  asection *prev = s->prev;
  if (prev)
    prev->next = next;
  else
    abfd->sections = next;
  if (next)
    next->prev = prev;
  else
    abfd->section_last = prev;
}

extrn void
bfd_section_list_append (bfd *abfd, asection *s)
{
  s->next = 0;
  if (abfd->section_last)
    {
      s->prev = abfd->section_last;
      abfd->section_last->next = s;
    }
  else
    {
      s->prev = 0;
      abfd->sections = s;
    }
  abfd->section_last = s;
}

extrn void
bfd_section_list_prepend (bfd *abfd, asection *s)
{
  s->prev = 0;
  if (abfd->sections)
    {
      s->next = abfd->sections;
      abfd->sections->prev = s;
    }
  else
    {
      s->next = 0;
      abfd->section_last = s;
    }
  abfd->sections = s;
}

extrn void
bfd_section_list_insert_after (bfd *abfd, asection *a, asection *s)
{
  asection *next = a->next;
  s->next = next;
  s->prev = a;
  a->next = s;
  if (next)
    next->prev = s;
  else
    abfd->section_last = s;
}

extrn void
bfd_section_list_insert_before (bfd *abfd, asection *b, asection *s)
{
  asection *prev = b->prev;
  s->prev = prev;
  s->next = b;
  b->prev = s;
  if (prev)
    prev->next = s;
  else
    abfd->sections = s;
}

extrn bool
bfd_section_removed_from_list (const bfd *abfd, const asection *s)
{
  return s->next ? s->next->prev != s : abfd->section_last != s;
}

extrn char *
bfd_debug_name_to_zdebug (bfd *abfd, const char *name)
{
  size_t len = strlen (name);
  char *new_name = (char *) bfd_alloc (abfd, len + 2);
  if (new_name == NULL)
    return NULL;
  new_name[0] = '.';
  new_name[1] = 'z';
  memcpy (new_name + 2, name + 1, len);
  return new_name;
}

extrn char *
bfd_zdebug_name_to_debug (bfd *abfd, const char *name)
{
  size_t len = strlen (name);
  char *new_name = (char *) bfd_alloc (abfd, len);
  if (new_name == NULL)
    return NULL;
  new_name[0] = '.';
  memcpy (new_name + 1, name + 2, len - 1);
  return new_name;
}



extrn unsigned int
bfd_get_reloc_size (reloc_howto_type *howto)
{
  return howto->size;
}

extrn const char *
bfd_get_target (const bfd *abfd)
{
  return abfd->xvec->name;
}

extrn enum bfd_flavour
bfd_get_flavour (const bfd *abfd)
{
  return abfd->xvec->flavour;
}

extrn flagword
bfd_applicable_file_flags (const bfd *abfd)
{
  return abfd->xvec->object_flags;
}

extrn bool
bfd_family_coff (const bfd *abfd)
{
  return (bfd_get_flavour (abfd) == bfd_target_coff_flavour
	  || bfd_get_flavour (abfd) == bfd_target_xcoff_flavour);
}

extrn bool
bfd_big_endian (const bfd *abfd)
{
  return abfd->xvec->byteorder == BFD_ENDIAN_BIG;
}
extrn bool
bfd_little_endian (const bfd *abfd)
{
  return abfd->xvec->byteorder == BFD_ENDIAN_LITTLE;
}

extrn bool
bfd_header_big_endian (const bfd *abfd)
{
  return abfd->xvec->header_byteorder == BFD_ENDIAN_BIG;
}

extrn bool
bfd_header_little_endian (const bfd *abfd)
{
  return abfd->xvec->header_byteorder == BFD_ENDIAN_LITTLE;
}

extrn flagword
bfd_applicable_section_flags (const bfd *abfd)
{
  return abfd->xvec->section_flags;
}

extrn char
bfd_get_symbol_leading_char (const bfd *abfd)
{
  return abfd->xvec->symbol_leading_char;
}

extrn enum bfd_flavour
bfd_asymbol_flavour (const asymbol *sy)
{
  if ((sy->flags & BSF_SYNTHETIC) != 0)
    return bfd_target_unknown_flavour;
  return sy->the_bfd->xvec->flavour;
}

extrn bool
bfd_keep_unused_section_symbols (const bfd *abfd)
{
  return abfd->xvec->keep_unused_section_symbols;
}
