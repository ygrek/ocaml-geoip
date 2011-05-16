(* File generated from geoip.idl *)

type t
and charset =
  | GEOIP_CHARSET_ISO_8859_1
  | GEOIP_CHARSET_UTF8
and flags =
  | GEOIP_STANDARD
  | GEOIP_MEMORY_CACHE
  | GEOIP_CHECK_CACHE
  | GEOIP_INDEX_CACHE
  | GEOIP_MMAP_CACHE
and db_type =
  | GEOIP_COUNTRY_EDITION
  | GEOIP_REGION_EDITION_REV0
  | GEOIP_CITY_EDITION_REV0
  | GEOIP_ORG_EDITION
  | GEOIP_ISP_EDITION
  | GEOIP_CITY_EDITION_REV1
  | GEOIP_REGION_EDITION_REV1
  | GEOIP_PROXY_EDITION
  | GEOIP_ASNUM_EDITION
  | GEOIP_NETSPEED_EDITION
  | GEOIP_DOMAIN_EDITION
  | GEOIP_COUNTRY_EDITION_V6
  | GEOIP_LOCATIONA_EDITION
  | GEOIP_ACCURACYRADIUS_EDITION
  | GEOIP_CITYCONFIDENCE_EDITION
  | GEOIP_CITYCONFIDENCEDIST_EDITION
  | GEOIP_LARGE_COUNTRY_EDITION
  | GEOIP_LARGE_COUNTRY_EDITION_V6
and proxy_type =
  | GEOIP_ANON_PROXY
  | GEOIP_HTTP_X_FORWARDED_FOR_PROXY
  | GEOIP_HTTP_CLIENT_IP_PROXY
and netspeed =
  | GEOIP_UNKNOWN_SPEED
  | GEOIP_DIALUP_SPEED
  | GEOIP_CABLEDSL_SPEED
  | GEOIP_CORPORATE_SPEED

(** GeoIP database library *)

external setup_custom_directory : string -> unit
	= "camlidl_geoip_GeoIP_setup_custom_directory"

external is_db_avail : db_type -> bool
	= "camlidl_geoip_GeoIP_db_avail"

(** Open GeoIP database specified by [path] if given, 
otherwise open database by [db_type] if given, otherwise open default database. 
@raise Failure if database cannot be opened *)
val init_exn : ?path:string -> ?db:db_type -> flags -> t

external close : t -> unit
	= "camlidl_geoip_GeoIP_delete"

external country_code_by_addr : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_code_by_addr"

external country_code_by_name : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_code_by_name"

external country_code3_by_addr : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_code3_by_addr"

external country_code3_by_name : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_code3_by_name"

external country_name_by_addr : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_name_by_addr"

external country_name_by_name : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_name_by_name"

external country_name_by_ipnum : t -> int32 -> string option
	= "camlidl_geoip_GeoIP_country_name_by_ipnum"

external country_code_by_ipnum : t -> int32 -> string option
	= "camlidl_geoip_GeoIP_country_code_by_ipnum"

external country_code3_by_ipnum : t -> int32 -> string option
	= "camlidl_geoip_GeoIP_country_code3_by_ipnum"

external country_code_by_addr_v6 : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_code_by_addr_v6"

external country_code_by_name_v6 : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_code_by_name_v6"

external country_code3_by_addr_v6 : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_code3_by_addr_v6"

external country_code3_by_name_v6 : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_code3_by_name_v6"

external country_name_by_addr_v6 : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_name_by_addr_v6"

external country_name_by_name_v6 : t -> string -> string option
	= "camlidl_geoip_GeoIP_country_name_by_name_v6"

external id_by_addr : t -> string -> int
	= "camlidl_geoip_GeoIP_id_by_addr"

external id_by_name : t -> string -> int
	= "camlidl_geoip_GeoIP_id_by_name"

external id_by_ipnum : t -> int -> int
	= "camlidl_geoip_GeoIP_id_by_ipnum"

external id_by_addr_v6 : t -> string -> int
	= "camlidl_geoip_GeoIP_id_by_addr_v6"

external id_by_name_v6 : t -> string -> int
	= "camlidl_geoip_GeoIP_id_by_name_v6"

external num_countries : unit -> int
	= "camlidl_geoip_GeoIP_num_countries"

external database_info : t -> string
	= "camlidl_geoip_GeoIP_database_info"

external database_edition : t -> int
	= "camlidl_geoip_GeoIP_database_edition"

external charset : t -> charset
	= "camlidl_geoip_GeoIP_charset"

external set_charset : t -> charset -> charset
	= "camlidl_geoip_GeoIP_set_charset"

