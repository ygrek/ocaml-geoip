/* File generated from geoip.idl */

#include <stddef.h>
#include <string.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/callback.h>
#ifdef Custom_tag
#include <caml/custom.h>
#include <caml/bigarray.h>
#endif
#include <caml/camlidlruntime.h>

#include <GeoIP.h>

typedef GeoIP* t;

void camlidl_ml2c_geoip_t(value _v1, t * _c2, camlidl_ctx _ctx)
{
  *_c2 = *((t *) Bp_val(_v1));
}

value camlidl_c2ml_geoip_t(t * _c2, camlidl_ctx _ctx)
{
value _v1;
  _v1 = camlidl_alloc((sizeof(t) + sizeof(value) - 1) / sizeof(value), Abstract_tag);
  *((t *) Bp_val(_v1)) = *_c2;
  return _v1;
}

int camlidl_transl_table_geoip_enum_1[2] = {
  GEOIP_CHARSET_ISO_8859_1,
  GEOIP_CHARSET_UTF8,
};

int camlidl_ml2c_geoip_enum_charset(value _v1)
{
  int _c2;
  _c2 = camlidl_transl_table_geoip_enum_1[Int_val(_v1)];
  return _c2;
}

value camlidl_c2ml_geoip_enum_charset(int _c1)
{
  value _v2;
  switch(_c1) {
  case GEOIP_CHARSET_ISO_8859_1: _v2 = Val_int(0); break;
  case GEOIP_CHARSET_UTF8: _v2 = Val_int(1); break;
  default: invalid_argument("enum charset: bad enum charset value");
  }
  return _v2;
}

int camlidl_transl_table_geoip_enum_2[5] = {
  GEOIP_STANDARD,
  GEOIP_MEMORY_CACHE,
  GEOIP_CHECK_CACHE,
  GEOIP_INDEX_CACHE,
  GEOIP_MMAP_CACHE,
};

int camlidl_ml2c_geoip_enum_flags(value _v1)
{
  int _c2;
  _c2 = camlidl_transl_table_geoip_enum_2[Int_val(_v1)];
  return _c2;
}

value camlidl_c2ml_geoip_enum_flags(int _c1)
{
  value _v2;
  _v2 = camlidl_find_enum(_c1, camlidl_transl_table_geoip_enum_2, 5, "enum flags: bad enum flags value");
  return _v2;
}

int camlidl_transl_table_geoip_enum_3[18] = {
  GEOIP_COUNTRY_EDITION,
  GEOIP_REGION_EDITION_REV0,
  GEOIP_CITY_EDITION_REV0,
  GEOIP_ORG_EDITION,
  GEOIP_ISP_EDITION,
  GEOIP_CITY_EDITION_REV1,
  GEOIP_REGION_EDITION_REV1,
  GEOIP_PROXY_EDITION,
  GEOIP_ASNUM_EDITION,
  GEOIP_NETSPEED_EDITION,
  GEOIP_DOMAIN_EDITION,
  GEOIP_COUNTRY_EDITION_V6,
  GEOIP_LOCATIONA_EDITION,
  GEOIP_ACCURACYRADIUS_EDITION,
  GEOIP_CITYCONFIDENCE_EDITION,
  GEOIP_CITYCONFIDENCEDIST_EDITION,
  GEOIP_LARGE_COUNTRY_EDITION,
  GEOIP_LARGE_COUNTRY_EDITION_V6,
};

int camlidl_ml2c_geoip_enum_db_type(value _v1)
{
  int _c2;
  _c2 = camlidl_transl_table_geoip_enum_3[Int_val(_v1)];
  return _c2;
}

value camlidl_c2ml_geoip_enum_db_type(int _c1)
{
  value _v2;
  _v2 = camlidl_find_enum(_c1, camlidl_transl_table_geoip_enum_3, 18, "enum db_type: bad enum db_type value");
  return _v2;
}

int camlidl_transl_table_geoip_enum_4[3] = {
  GEOIP_ANON_PROXY,
  GEOIP_HTTP_X_FORWARDED_FOR_PROXY,
  GEOIP_HTTP_CLIENT_IP_PROXY,
};

int camlidl_ml2c_geoip_enum_proxy_type(value _v1)
{
  int _c2;
  _c2 = camlidl_transl_table_geoip_enum_4[Int_val(_v1)];
  return _c2;
}

value camlidl_c2ml_geoip_enum_proxy_type(int _c1)
{
  value _v2;
  switch(_c1) {
  case GEOIP_ANON_PROXY: _v2 = Val_int(0); break;
  case GEOIP_HTTP_X_FORWARDED_FOR_PROXY: _v2 = Val_int(1); break;
  case GEOIP_HTTP_CLIENT_IP_PROXY: _v2 = Val_int(2); break;
  default: invalid_argument("enum proxy_type: bad enum proxy_type value");
  }
  return _v2;
}

int camlidl_transl_table_geoip_enum_5[4] = {
  GEOIP_UNKNOWN_SPEED,
  GEOIP_DIALUP_SPEED,
  GEOIP_CABLEDSL_SPEED,
  GEOIP_CORPORATE_SPEED,
};

int camlidl_ml2c_geoip_enum_netspeed(value _v1)
{
  int _c2;
  _c2 = camlidl_transl_table_geoip_enum_5[Int_val(_v1)];
  return _c2;
}

value camlidl_c2ml_geoip_enum_netspeed(int _c1)
{
  value _v2;
  switch(_c1) {
  case GEOIP_UNKNOWN_SPEED: _v2 = Val_int(0); break;
  case GEOIP_DIALUP_SPEED: _v2 = Val_int(1); break;
  case GEOIP_CABLEDSL_SPEED: _v2 = Val_int(2); break;
  case GEOIP_CORPORATE_SPEED: _v2 = Val_int(3); break;
  default: invalid_argument("enum netspeed: bad enum netspeed value");
  }
  return _v2;
}

value camlidl_geoip_GeoIP_setup_custom_directory(
	value _v_dir)
{
  char *dir; /*in*/
  dir = String_val(_v_dir);
  GeoIP_setup_custom_directory(dir);
  return Val_unit;
}

#include "geoip_init.h"

value camlidl_geoip_GeoIP_db_avail(
	value _v_type)
{
  int type; /*in*/
  int _res;
  value _vres;

  type = camlidl_ml2c_geoip_enum_db_type(_v_type);
  _res = GeoIP_db_avail(type);
  _vres = Val_int(_res);
  return _vres;
}

value camlidl_geoip_GeoIP_delete(
	value _v_gi)
{
  t gi; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  GeoIP_delete(gi);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_geoip_GeoIP_country_code_by_addr(
	value _v_gi,
	value _v_addr)
{
  t gi; /*in*/
  char const *addr; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  addr = String_val(_v_addr);
  _res = GeoIP_country_code_by_addr(gi, addr);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_code_by_name(
	value _v_gi,
	value _v_host)
{
  t gi; /*in*/
  char const *host; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  host = String_val(_v_host);
  _res = GeoIP_country_code_by_name(gi, host);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_code3_by_addr(
	value _v_gi,
	value _v_addr)
{
  t gi; /*in*/
  char const *addr; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  addr = String_val(_v_addr);
  _res = GeoIP_country_code3_by_addr(gi, addr);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_code3_by_name(
	value _v_gi,
	value _v_host)
{
  t gi; /*in*/
  char const *host; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  host = String_val(_v_host);
  _res = GeoIP_country_code3_by_name(gi, host);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_name_by_addr(
	value _v_gi,
	value _v_addr)
{
  t gi; /*in*/
  char const *addr; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  addr = String_val(_v_addr);
  _res = GeoIP_country_name_by_addr(gi, addr);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_name_by_name(
	value _v_gi,
	value _v_host)
{
  t gi; /*in*/
  char const *host; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  host = String_val(_v_host);
  _res = GeoIP_country_name_by_name(gi, host);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_name_by_ipnum(
	value _v_gi,
	value _v_ipnum)
{
  t gi; /*in*/
  unsigned long ipnum; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  ipnum = Int32_val(_v_ipnum);
  _res = GeoIP_country_name_by_ipnum(gi, ipnum);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_code_by_ipnum(
	value _v_gi,
	value _v_ipnum)
{
  t gi; /*in*/
  unsigned long ipnum; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  ipnum = Int32_val(_v_ipnum);
  _res = GeoIP_country_code_by_ipnum(gi, ipnum);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_code3_by_ipnum(
	value _v_gi,
	value _v_ipnum)
{
  t gi; /*in*/
  unsigned long ipnum; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  ipnum = Int32_val(_v_ipnum);
  _res = GeoIP_country_code3_by_ipnum(gi, ipnum);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_code_by_addr_v6(
	value _v_gi,
	value _v_addr)
{
  t gi; /*in*/
  char const *addr; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  addr = String_val(_v_addr);
  _res = GeoIP_country_code_by_addr_v6(gi, addr);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_code_by_name_v6(
	value _v_gi,
	value _v_host)
{
  t gi; /*in*/
  char const *host; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  host = String_val(_v_host);
  _res = GeoIP_country_code_by_name_v6(gi, host);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_code3_by_addr_v6(
	value _v_gi,
	value _v_addr)
{
  t gi; /*in*/
  char const *addr; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  addr = String_val(_v_addr);
  _res = GeoIP_country_code3_by_addr_v6(gi, addr);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_code3_by_name_v6(
	value _v_gi,
	value _v_host)
{
  t gi; /*in*/
  char const *host; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  host = String_val(_v_host);
  _res = GeoIP_country_code3_by_name_v6(gi, host);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_name_by_addr_v6(
	value _v_gi,
	value _v_addr)
{
  t gi; /*in*/
  char const *addr; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  addr = String_val(_v_addr);
  _res = GeoIP_country_name_by_addr_v6(gi, addr);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_country_name_by_name_v6(
	value _v_gi,
	value _v_host)
{
  t gi; /*in*/
  char const *host; /*in*/
  char const *_res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  host = String_val(_v_host);
  _res = GeoIP_country_name_by_name_v6(gi, host);
  if (_res == NULL) {
    _vres = Val_int(0);
  } else {
    _v1 = copy_string(_res);
    Begin_root(_v1)
      _vres = camlidl_alloc_small(1, 0);
      Field(_vres, 0) = _v1;
    End_roots();
  }
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_charset(
	value _v_gi)
{
  t gi; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  _res = GeoIP_charset(gi);
  _vres = camlidl_c2ml_geoip_enum_charset(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_geoip_GeoIP_set_charset(
	value _v_gi,
	value _v_charset)
{
  t gi; /*in*/
  int charset; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_geoip_t(_v_gi, &gi, _ctx);
  charset = camlidl_ml2c_geoip_enum_charset(_v_charset);
  _res = GeoIP_set_charset(gi, charset);
  _vres = camlidl_c2ml_geoip_enum_charset(_res);
  camlidl_free(_ctx);
  return _vres;
}

