
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

#define Some_val(v) (Field(v,0))

#define Geoip_val(v) ((GeoIP*)(v))

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

CAMLprim value caml_geoip_open(value v_path, value v_flag)
{
    CAMLparam2(v_path,v_flag);
    GeoIP* gi = NULL;

    if (Val_none != v_path)
      gi = GeoIP_open(String_val(Some_val(v_path)), Geoip_flag_val(v_flag));
    else
      gi = GeoIP_new(Geoip_flag_val(v_flag));

    if (NULL != gi)
      CAMLreturn(Val_some((value)gi));
    else
      CAMLreturn(Val_none);
}

CAMLprim value caml_geoip_country_code_by_name(value gi, value host)
{
    CAMLparam2(gi, host);

    char const* code = GeoIP_country_code_by_name(Geoip_val(gi), String_val(host));

    if (NULL != code)
      CAMLreturn(Val_some(caml_copy_string(code)));
    else
      CAMLreturn(Val_none);
}

CAMLprim value caml_geoip_close(value gi)
{
    CAMLparam1(gi);
    GeoIP_delete(Geoip_val(gi));
    CAMLreturn(Val_unit);
}
