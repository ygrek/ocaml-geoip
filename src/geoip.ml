(** libGeoIP wrapper *)

type t

type geoip_db_flag = 
  | STANDARD
  | MEMORY_CACHE
  | CHECK_CACHE
  | INDEX_CACHE
  | MMAP_CACHE

external open_file : string -> geoip_db_flag -> t option = "caml_geoip_open"
external country_code_by_name : t -> string -> string option = "caml_geoip_country_code_by_name"
external close : t -> unit = "caml_geoip_close"

