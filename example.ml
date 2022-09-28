
open Printf
open Geoip

let show = function
| None -> "None"
| Some s -> s

let pr fmt = ksprintf print_endline fmt

let test1 () =
  let test gi =
    let code = country_code_by_name gi in
    let ips = [
      "195.189.143.147"; (* opera.com, NO *)
      "195.214.195.105"; (* ukr.net, UA *)
      "81.19.70.3";      (* rambler.ru, RU *)
      "127.0.0.1"
    ] in
    let t1 = Unix.gettimeofday () in
    for _i = 1 to 1_000_000 do
      List.iter (fun s -> ignore (code s)) ips
    done;
    pr "%.2f seconds" (Unix.gettimeofday () -. t1);
    List.iter (fun s -> pr "%s -> %s" s (show (code s))) ips
  in
  let gi = init_exn GEOIP_MEMORY_CACHE in
  test gi;
  close gi

let interactive () = 
  let gi = init_exn GEOIP_MEMORY_CACHE in
  let rec loop () =
    match input_line stdin with
    | "" -> ()
    | s ->
      pr "%s %s" (show (country_code_by_name gi s)) (show (country_name_by_name gi s));
      loop ()
  in
  pr "Input address. Empty string to exit.";
  loop ();
  close gi

let test2 () =
  let db = init_exn ~db:GEOIP_COUNTRY_EDITION GEOIP_STANDARD in
  pr "%s %s %s"
    (show (country_code_by_addr db "1.0.0.1"))
    (show (country_code3_by_addr db "1.0.0.1"))
    (show (country_name_by_addr db "1.0.0.1"));
  close db

let () = 
  test1 ();
  test2 ();
  interactive ()

