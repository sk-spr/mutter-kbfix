/*
 * Cogl
 *
 * A Low Level GPU Graphics and Utilities API
 *
 * Copyright (C) 2010 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 *
 * Authors:
 *   Robert Bragg <robert@linux.intel.com>
 */

#include "config.h"

#include "cogl/cogl-attribute-buffer.h"
#include "cogl/cogl-attribute-buffer-private.h"
#include "cogl/cogl-context-private.h"

G_DEFINE_FINAL_TYPE (CoglAttributeBuffer, cogl_attribute_buffer, COGL_TYPE_BUFFER)

static void
cogl_attribute_buffer_class_init (CoglAttributeBufferClass *klass)
{
}

static void
cogl_attribute_buffer_init (CoglAttributeBuffer *buffer)
{
}

CoglAttributeBuffer *
cogl_attribute_buffer_new_with_size (CoglContext *context,
                                     size_t       bytes)
{
  CoglDriver *driver = cogl_context_get_driver (context);
  CoglAttributeBuffer *buffer;

  buffer = g_object_new (COGL_TYPE_ATTRIBUTE_BUFFER,
                         "context", context,
                         "impl", cogl_driver_create_buffer_impl (driver),
                         "size", (uint64_t) bytes,
                         "default-target", COGL_BUFFER_BIND_TARGET_ATTRIBUTE_BUFFER,
                         "update-hint", COGL_BUFFER_UPDATE_HINT_STATIC,
                         NULL);

  return buffer;
}

CoglAttributeBuffer *
cogl_attribute_buffer_new (CoglContext *context,
                           size_t       bytes,
                           const void  *data)
{
  CoglAttributeBuffer *buffer;

  buffer = cogl_attribute_buffer_new_with_size (context, bytes);

  /* Note: to keep the common cases simple this API doesn't throw
   * GErrors, so developers can assume this function never returns
   * NULL and we will simply abort on error.
   *
   * Developers wanting to catch errors can use
   * cogl_attribute_buffer_new_with_size() and catch errors when later
   * calling cogl_buffer_set_data() or cogl_buffer_map().
   */

  /* XXX: NB: for Cogl 2.0 we don't allow NULL data here but we can't
   * break the api for 1.x and so we keep the check for now. */
  if (data)
    cogl_buffer_set_data (COGL_BUFFER (buffer),
                          0,
                          data,
                          bytes);

  return buffer;
}
