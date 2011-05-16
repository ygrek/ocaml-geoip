
GEN=index.html
WEB=geoip.forge.ocamlcore.org:/home/groups/geoip/htdocs

html: $(GEN)

%.html: %.brtx
	brtx -html -doc -i $< -o $@

upload: index.html
	rsync -avihz $< $(WEB)/
	make -C .. doc
	rsync -avihz ../_build/src/api.docdir/ $(WEB)/api

clean:
	rm -f $(GEN)

