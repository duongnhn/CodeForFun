// https://leetcode.com/problems/validate-ip-address/
// 468. Validate IP Address
// Medium

#include <string>
#include <sstream>
using namespace std;

class ValidateIPAddress {
public:
  string validIPAddress(string IP) {
    if (validIPv4Address(IP)) {
      return "IPv4";
    }
    if (validIPv6Address(IP)) {
      return "IPv6";
    }
    return "Neither";
  }

  bool validIPv4Address(string IP) {
    size_t current, previous = 0;
    const string& delimiter = ".";
    current = IP.find_first_of(delimiter);
    int count = 0;
    while (current != string::npos) {
      if (!validXInIPv4Address(IP.substr(previous, current - previous))) {
        return false;
      }
      count++;
      if (count > 3) return false;
      previous = current + 1;
      current = IP.find_first_of(delimiter, previous);
    }
    if (count != 3) return false;
    if (!validXInIPv4Address(IP.substr(previous, current - previous))) {
      return false;
    }
    return true;
  }

  bool validXInIPv4Address(string xi) {
    if (xi.empty()) return false;
    if (xi.length() > 3) return false;
    if (xi.length() >= 2 && xi[0] == '0') return false;
    for (int i = 0; i < xi.length(); i++) {
      if (!isdigit(xi[i])) return false;
    }
    // convert to number
    stringstream ss(xi);
    int num;
    ss >> num;
    if (num < 0 || num > 255) return false;
    return true;
  }

  bool validIPv6Address(string IP) {
    size_t current, previous = 0;
    const string& delimiter = ":";
    current = IP.find_first_of(delimiter);
    int count = 0;
    while (current != string::npos) {
      if (!validXInIPv6Address(IP.substr(previous, current - previous))) {
        return false;
      }
      count++;
      if (count > 7) return false;
      previous = current + 1;
      current = IP.find_first_of(delimiter, previous);
    }
    if (count != 7) return false;
    if (!validXInIPv6Address(IP.substr(previous, current - previous))) {
      return false;
    }
    return true;
  }

  bool validXInIPv6Address(string xi) {
    if (xi.length() > 4 || xi.length() < 1) return false;
    const string& possibleCharacters = "0123456789abcdefABCDEF";
    for (int i = 0; i < xi.length(); i++) {
      if (possibleCharacters.find_first_of(xi[i]) == string::npos) {
        return false;
      }
    }
    return true;
  }
};