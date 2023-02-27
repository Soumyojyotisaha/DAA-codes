#include <iostream>
#include <string>

int main()
{
    std::string p, s;
    std::cout << "Enter the pattern string: ";
    std::getline(std::cin, p);
    std::cout << "Enter the text string: ";
    std::getline(std::cin, s);

    int maxchar = 101;
    int mod = 10007;
    int plen = p.length();
    int slen = s.length();
    int h = 1;
    std::size_t ph = 0, th = 0;
    for (int i = 0; i < plen - 1; i++) {
        h = (h * maxchar) % mod;
    }
    for (int i = 0; i < plen; i++) {
        ph = (ph * maxchar + p[i] - maxchar) % mod;
        th = (th * maxchar + s[i] - maxchar) % mod;
    }
    bool found = false;
    std::cout << "Pattern found at indices: ";
    for (int i = 0; i < slen - plen + 1; i++) {
        if (ph == th) {
            if (s.substr(i, plen) == p) {
                found = true;
                std::cout << i << " ";
            }
        }
        if (i < slen - plen) {
            th = ((th - (s[i] - maxchar) * h % mod + mod) % mod * maxchar % mod + s[i + plen] - maxchar) % mod;
        }
    }
    if (!found) {
        std::cout << "none";
    }
    std::cout << std::endl;
}
