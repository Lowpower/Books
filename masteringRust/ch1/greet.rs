use std::env;

fn main() {
  let name = env::args().skip(1).next();
  match name {
    Some(n) => println!("Hi there ! {}", n),
    None => panic!("Didnt receive any name ?")
  }
}