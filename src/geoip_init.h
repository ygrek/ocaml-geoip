
CAMLprim value caml_geoip_init(value v_path, value v_type, value v_flags)
{
    int flags;
    t _res;
    value _vres;

    struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
    camlidl_ctx _ctx = &_ctxs;
    flags = camlidl_ml2c_geoip_enum_flags(v_flags);

    if (Val_int(0) != v_path)
      _res = GeoIP_open(String_val(Field(v_path,0)), flags);
    else if (Val_int(0) != v_type)
      _res = GeoIP_open_type(camlidl_ml2c_geoip_enum_db_type(Field(v_type,0)), flags);
    else
      _res = GeoIP_new(flags);

    if (NULL == _res)
      caml_failwith("geoip: cannot open database");

    _vres = camlidl_c2ml_geoip_t(&_res, _ctx);
    camlidl_free(_ctx);
    return _vres;
}

