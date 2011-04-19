(** GeoIP library bindings *)

(** database handle *)
type t

type db_flag =
  | STANDARD
  | MEMORY_CACHE
  | CHECK_CACHE
  | INDEX_CACHE
  | MMAP_CACHE

(** {2 Setup} *)

(** Open GeoIP database (use [path] if given, otherwise use builtin path). *)
external init : ?path:string -> db_flag -> t option = "caml_geoip_open"

(* external open_type : db_type -> db_flag -> t option = "caml_geoip_open_type" *)

(** Close database and invalidate handle *)
external close : t -> unit = "caml_geoip_close"

(** {2 Query} *)

external country_code_by_name : t -> string -> string option = "caml_geoip_country_code_by_name"

