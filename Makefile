build:
	make -C ./uuid_c
	make -C ./uuid_rust

	mkdir ./bin/
	cp ./uuid_c/uuid_c ./bin/uuid_c
	cp ./uuid_rust/target/release/uuid_rust ./bin/uuid_rust


clean:
	rm -r ./bin/
	make clean -C ./uuid_c
	make clean -C ./uuid_rust

run:
	./bin/uuid_rust
	./bin/uuid_c
