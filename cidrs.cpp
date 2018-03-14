#include <boost/python.hpp>
#include <sstream>
#include <string>

// TODO was getting error with std::to_string
template<class T>
std::string to_string(const T &value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

uint32_t ipToUInt(const std::string ip) {
  int a, b, c, d;
  sscanf(ip.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
  return (a<<24) + (b<<16) + (c<<8) + d;
}

// TODO trouble with conversion from python
bool isIpInRange(char* ip_star, char* network_star) {
    std::string ip, network;
    ip.append(ip_star);
    network.append(network_star);

    uint32_t ip_addr = ipToUInt(ip);
    uint32_t network_addr = ipToUInt(network);
    int a, b, c, d, postfix; // figure this out stupid
    sscanf(network.c_str(), "%d.%d.%d.%d/%d", &a, &b, &c, &d, &postfix);

    unsigned long mask = (0xFFFFFFFF << (32 - postfix)) & 0xFFFFFFFF;
    uint32_t mask_addr = ipToUInt(to_string(mask>>24) + "." + to_string((mask>>16) & 0xFF) + "." + to_string((mask>>8) & 0xFF) + "." + to_string(mask & 0xFF));

    uint32_t net_lower = (network_addr & mask_addr);
    return (net_lower <= ip_addr && ip_addr <= (net_lower | (~mask_addr)));
}

bool isIpInRanges(char* ip_star, boost::python::list& networks_star) {

    for (int i = 0; i < len(networks_star); i++){
      char* range = boost::python::extract<char*>(networks_star[i]);
      if (isIpInRange(ip_star, range)) {
        return true;
      }
    }
    return false;
}

//void test(const std::string ip, const std::string network, bool expected) {
//    printf((isIpInRange(ip, network) == expected ? "Success %s %s %s\n" : "Failure %s %s %s\n"), ip.c_str(), expected ? "in" : "NOT in",network.c_str());
//}

//int main() {
//    test("192.168.1.3", "192.168.1.0/30", true);
//    test("192.168.1.1", "192.168.1.2/32", false);
//    test("192.168.1.2", "192.168.1.2/32", true);
//    test("192.168.1.3", "192.168.1.2/32", false);
//}

BOOST_PYTHON_MODULE(cidrs)
{
    using namespace boost::python;
	def("isIpInRange", isIpInRange);
	def("isIpInRanges", isIpInRanges);
}