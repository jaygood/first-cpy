# import this_is_hello
#
# print(this_is_hello.yo())
# print(this_is_hello.add(131, 12))

import cidrs

# print(cidrs.tester("hello"))
print(cidrs.isIpInRange("192.168.1.3", "192.168.1.0/30"))
print(cidrs.isIpInRange("192.168.1.4", "192.168.1.0/30"))
print(cidrs.isIpInRanges("192.168.1.4", ["192.168.1.0/30", "182.168.1.4/30"]))
