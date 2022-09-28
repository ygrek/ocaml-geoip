.PHONY: build clean doc example

build:
	dune build

clean:
	dune clean

doc:
	dune build @doc

example:
	dune exec -- ./example.exe

.PHONY: gen

gen:
	cd src && camlidl -no-include geoip.idl

VERSION=0.0.4
NAME=ocaml-geoip-$(VERSION)

.PHONY: release
release:
	git tag -a -m $(VERSION) v$(VERSION)
	git archive --prefix=$(NAME)/ v$(VERSION) | gzip > $(NAME).tar.gz
	gpg -a -b $(NAME).tar.gz > $(NAME).tar.gz.asc
