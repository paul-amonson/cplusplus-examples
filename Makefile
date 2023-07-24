release:
	mkdir -p _build
	cmake -S . -B _build
	make -C _build

debug:
	mkdir -p _build
	cmake -S . -B _build
	make -C _build

all:	release

clean:
	rm -rf _build
