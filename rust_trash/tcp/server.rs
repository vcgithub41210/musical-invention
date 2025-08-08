use std::net::TcpStream;
use std::io::{Read,Write};

fn main(){
    let mut stream = TcpStream::connect("127.0.0.1:6379").unwrap();
    let msg = String::from("test message");
    stream.write_all(msg.as_bytes()).unwrap();
}
