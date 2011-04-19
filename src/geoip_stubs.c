
#include <GeoIP.h>

#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/callback.h>

#define Val_none Val_int(0)

static value Val_some(value v)
{
    CAMLparam1( v );
    CAMLlocal1( some );
    some = caml_alloc(1, 0);
    Store_field( some, 0, v );
    CAMLreturn( some );
}

static int Geoip_flag_val(value v)
{
    static const GeoIPOptions table_flags[] =
    {
      GEOIP_STANDARD,
    	GEOIP_MEMORY_CACHE,
    	GEOIP_CHECK_CACHE,
    	GEOIP_INDEX_CACHE,
    	GEOIP_MMAP_CACHE
    };

    int i = Int_val(v);
    if (i >= 0 && i < sizeof(table_flags)/sizeof(table_flags[0]))
    {
      return table_flags[i];
    }
    caml_invalid_argument("Geoip_flag_val");
    return 0; // never happens
}

CAMLprim value caml_geoip_open(value path, value flag)
{
    CAMLparam1(path);

    char const* path_c = String_val(path);
    GeoIP* gi = GeoIP_open(path_c, Geoip_flag_val(flag));
    if (gi)
      CAMLreturn(Val_some((value)gi)); 
    else 
      CAMLreturn(Val_none);
}

CAMLprim value caml_geoip_country_code_by_name(value gi, value host)
{
    CAMLparam2(gi, host);

    char const* host_c = String_val(host);
    char const* code = GeoIP_country_code_by_name((GeoIP*)gi, host_c);

    if (code)
      CAMLreturn(Val_some(caml_copy_string(code)));
    else
      CAMLreturn(Val_none);
}

CAMLprim value caml_geoip_close(value gi)
{
    CAMLparam1(gi);
    GeoIP_delete((GeoIP*)gi);
    CAMLreturn(Val_unit);
}
