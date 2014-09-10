/* 
 * File:   generator.h
 * Author: williamyu
 *
 * Created on June 29, 2014, 4:30 PM
 */

#ifndef GENERATOR_H
#define	GENERATOR_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <libxml2/libxml/xmlreader.h>
#include <glib-2.0/glib.h>
#include "xml-parser.h"


#define HEADER_TEMPLATE "header-template"
#define INLINE_TRANSLATION "${translator} (${name})"
#define SOURCE_TEMPLATE "source-template"
#define COMMON_HEADER "common-header"
#define HEADER_STRUCTURE_BOILERPLATE_TEMPLATE "header-structure-boilerplate-template"
#define SOURCE_STRUCTURE_BOILERPLATE_TEMPLATE "source-structure-boilerplate-template"
#define LICENCE_HEADER \
"/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */\n\
/*\n\
 * This library is free software: you can redistribute it and/or modify it\n\
 * under the terms of the GNU Lesser General Public License as published by\n\
 * the Free Software Foundation.\n\
 *\n\
 * This library is distributed in the hope that it will be useful, but\n\
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY\n\
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License\n\
 * for more details.\n\
 *\n\
 * You should have received a copy of the GNU Lesser General Public License\n\
 * along with this library. If not, see <http://www.gnu.org/licenses/>.\n\
 */\n"
#define BUFFER_SIZE 2000
#define TAB_SIZE 8
#define RET_TAB_COUNT 2
#define METHOD_NAME_TAB_COUNT 4
#define COMMENT_LINE_LENGTH 100

GHashTable *defaultValues;
GHashTable *allStructures;
GHashTable *type2Structure;

gchar *get_upper_camel_from_lower_snake (const gchar *lowerSnake);
gchar *get_lower_snake_from_upper_camel (const gchar *upperCamel);
gchar *get_upper_snake_from_lower_snake (const gchar *lowerSnake);
gchar *get_lower_train_from_lower_snake (const gchar *lowerSnake);
gchar *get_upper_snake_from_upper_camel (const gchar *upperCamel);
gchar *get_lower_train_from_upper_camel (const gchar *upperCamel);

gchar *get_source_method_code (Method *method);
gchar *get_inline_parameter (Parameter *para);
gchar *get_source_method_comment (Method *method);
gchar *get_source_method_proto (Method *method);
gchar *get_source_method_body (Method *method, const gchar *namespace);
gchar *get_source_destruction (Structure *structure);
gchar *get_source_method_checkers (Method *method);
gchar *get_source_method_checker (Parameter *para, Ret *ret);
gchar *get_source_run_time_checkers (Method *method, const gchar *namespace);
gchar *get_translator_name_for_return (gchar *upperCamel);
gchar *get_translator_for_paramter (Parameter *para);
gchar *get_translator_for_return (Ret *ret);

gchar *get_source_method_proto_new_full (Structure *structure);
gchar *get_source_method_proto_get_native_set_owner (Structure *structure);
gchar *get_source_method_proto_set_owner (Structure *structure);
gchar *get_source_method_proto_set_native (Structure *structure);
gchar *get_source_method_proto_set_is_global (Structure *structure);
gchar *get_source_method_proto_set_property (Structure *structure);
gchar *get_source_method_proto_get_property (Structure *structure);
gchar *get_source_method_proto_get_native_pointer_set_owner (Structure *structure);



GHashTable *get_hash_table_from_structure (Structure *structure);
void generate_header_method_protos (FILE *out, Structure *structure);
void generate_header_method_proto (FILE *out, Method *method);
void generate_header_method_new_full (FILE *out, Structure *structure);
void generate_header_method_get_type (FILE *out, Structure *structure);
void generate_header_method_get_native_set_owner (FILE *out, Structure *structure);
void generate_header_method_get_native_remove_owner (FILE *out, Structure *structure);
void generate_header_method_get_native_pointer_set_owner (FILE *out, Structure *structure);
void generate_header_method_steal_native (FILE *out, Structure *structure);
void generate_header_enums (FILE *out, Structure *structure);
void generate_header_enum (FILE *out, Enumeration *enumeration);
void generate_header_includes (FILE *out, Structure *structure);
void generate_source_includes (FILE *out, Structure *structure);
void generate_header_forward_declaration (FILE *out, Structure *structure);
void generate_header_structure_boilerplate (FILE *out, Structure *structure, GHashTable* table);
void generate_header (FILE *out, Structure *structure, GHashTable* table);
void generate_source (FILE *out, Structure *structure, GHashTable* table);
void generate_source_structure_boilerplate (FILE *out, Structure *structure, GHashTable* table);
void generate_conditional (FILE *out, Structure *structure, gchar *statement, GHashTable * table);
void generate_header_and_source (Structure *structure, gchar * dir);

#endif	/* GENERATOR_H */