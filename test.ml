
open OUnit
open Printf

let show = function
| None -> "None"
| Some s -> s

let test_geoip () =
  let test gi =
    let code = Geoip.country_code_by_name gi in
    let ips = [
      "195.189.143.147"; (* opera.com, NO *)
      "195.214.195.105"; (* ukr.net, UA *)
      "81.19.70.3";      (* rambler.ru, RU *)
      "127.0.0.1"
    ] in
    let t1 = Unix.gettimeofday () in
    for i = 1 to 1_000_000 do
      List.iter (fun s -> ignore (code s)) ips
    done;
    printf "%.2f seconds\n" (Unix.gettimeofday () -. t1);
    List.iter (fun s -> printf "%s -> %s\n" s (show (code s))) ips;
    Geoip.close gi
  in
  match Geoip.init Geoip.MEMORY_CACHE with
  | Some gi -> test gi
  | None -> skip_if true "no GeoIP.dat"

let geoip_loop () = 
  match Geoip.init Geoip.MEMORY_CACHE with
  | None -> failwith "no geoip"
  | Some gi ->
    let rec loop () =
      match input_line stdin with
      | "" -> ()
      | s ->
        print_endline (show (Geoip.country_code_by_name gi s));
        loop ()
    in
    loop ();
    Geoip.close gi

let _ = run_test_tt ("geoip" >:: test_geoip)

