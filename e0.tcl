#!/usr/bin/expect

set timeout 10

expect_after {
    timeout {
        puts "----> timeout <----\r"
        exit
    }
}

spawn qemu-system-x86_64 -nographic --serial mon:stdio -hdc kernel/kernel.img -hdd fat439/user.img

expect "*** System Shutdown ***\r"
send \001
send "x"
