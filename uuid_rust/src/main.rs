fn main() {
	const LENGTH: usize = 36;
	
	let mut uuid: Vec<u8> = vec![0x0; LENGTH];

	fn genhex() -> u8 {
		let n = rand::random::<u8>() % 0x67;
	
		if (n > 0x2f && n < 0x3a) || (n > 0x60 && n < 0x67) {
			return n;
		}
	
		genhex()
	}

	for mut i in 0..uuid.len() {
		if i == 8 || i == 13 || i == 18 || i == 23 {
			uuid[i] = 0x2d;
			i += 1;
		}
		uuid[i] = genhex();
	}

	let uuid: String = String::from_utf8(uuid).unwrap();
	println!("{}", uuid);
}
