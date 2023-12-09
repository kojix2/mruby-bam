/*
** mrb_bam.c - Bam class
**
** Copyright (c) kojix2 2023
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_bam.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  sam_hdr_t *hdr;
  bam1_t *bam1;
} mrb_bam_data;

static const struct mrb_data_type mrb_bam_data_type = {
  "mrb_bam_data", mrb_free,
};

static mrb_value mrb_bam_init(mrb_state *mrb, mrb_value self)
{
  mrb_bam_data *data;
  sam_hdr_t *hdr;
  bam1_t *bam1;

  data = (mrb_bam_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_bam_data_type;
  DATA_PTR(self) = NULL;

  return self;
}

static mrb_value mrb_bam_tid(mrb_state *mrb, mrb_value self)
{
  mrb_bam_data *data = DATA_PTR(self);

  return mrb_fixnum_value(data->bam1->core.tid);
}

static mrb_value mrb_bam_qname(mrb_state *mrb, mrb_value self)
{
  mrb_bam_data *data = DATA_PTR(self);

  return mrb_str_new_cstr(mrb, bam_get_qname(data->bam1));
}

void mrb_mruby_bam_gem_init(mrb_state *mrb)
{
  struct RClass *bam;
  bam = mrb_define_class(mrb, "Bam", mrb->object_class);
  mrb_define_method(mrb, bam, "initialize", mrb_bam_init, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, bam, "tid", mrb_bam_tid, MRB_ARGS_NONE());
  mrb_define_method(mrb, bam, "qname", mrb_bam_qname, MRB_ARGS_NONE());
  DONE;
}

void mrb_mruby_bam_gem_final(mrb_state *mrb)
{
}

