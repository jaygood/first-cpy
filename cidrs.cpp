#include <iostream>

uint32_t ipToUInt(const std::string ip) {
  int a, b, c, d;
  sscanf(ip.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
  return (a<<24) + (b<<16) + (c<<8) + d;
}

bool isIpInRange(const std::string ip, const std::string network) {
    uint32_t ip_addr = ipToUInt(ip);
    uint32_t network_addr = ipToUInt(network);
    int a, b, c, d, postfix; // figure this out stupid
    sscanf(network.c_str(), "%d.%d.%d.%d/%d", &a, &b, &c, &d, &postfix);

    unsigned long mask = (0xFFFFFFFF << (32 - postfix)) & 0xFFFFFFFF;
    uint32_t mask_addr = ipToUInt(std::to_string(mask>>24) + "." + std::to_string((mask>>16) & 0xFF) + "." + std::to_string((mask>>8) & 0xFF) + "." + std::to_string(mask & 0xFF));

    uint32_t net_lower = (network_addr & mask_addr);
    return (net_lower <= ip_addr && ip_addr <= (net_lower | (~mask_addr)));
}

void test(const std::string ip, const std::string network, bool expected) {
    printf((isIpInRange(ip, network) == expected ? "Success %s %s %s\n" : "Failure %s %s %s\n"), ip.c_str(), expected ? "in" : "NOT in",network.c_str());
}

int main() {
    test("192.168.1.3", "192.168.1.0/30", true);
    test("192.168.1.1", "192.168.1.2/32", false);
    test("192.168.1.2", "192.168.1.2/32", true);
    test("192.168.1.3", "192.168.1.2/32", false);
}