#include <iostream>

#include "base64.h"

int main() {
    const std::string s =
        "René Nyffenegger\n"
        "http://www.renenyffenegger.ch\n"
        "passion for data\n";

    std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    std::string decoded = base64_decode(encoded);

    std::cout << "encoded: " << std::endl << encoded << std::endl << std::endl;
    std::cout << "decoded: " << std::endl << decoded << std::endl;

    // Test all possibilites of fill bytes (none, one =, two ==)
    // References calculated with: https://www.base64encode.org/

    std::string rest0_original = "abc";
    std::string rest0_reference = "YWJj";

    std::string rest0_encoded = base64_encode(reinterpret_cast<const unsigned char*>(rest0_original.c_str()), rest0_original.length());
    std::string rest0_decoded = base64_decode(rest0_encoded);

    std::cout << "encoded:   " << rest0_encoded << std::endl;
    std::cout << "reference: " << rest0_reference << std::endl;
    std::cout << "decoded:   " << rest0_decoded << std::endl << std::endl;

    std::string rest1_original = "abcd";
    std::string rest1_reference = "YWJjZA==";

    std::string rest1_encoded = base64_encode(reinterpret_cast<const unsigned char*>(rest1_original.c_str()), rest1_original.length());
    std::string rest1_decoded = base64_decode(rest1_encoded);

    std::cout << "encoded:   " << rest1_encoded << std::endl;
    std::cout << "reference: " << rest1_reference << std::endl;
    std::cout << "decoded:   " << rest1_decoded << std::endl << std::endl;

    std::string rest2_original = "abcde";
    std::string rest2_reference = "YWJjZGU=";

    std::string rest2_encoded = base64_encode(reinterpret_cast<const unsigned char*>(rest2_original.c_str()), rest2_original.length());
    std::string rest2_decoded = base64_decode(rest2_encoded);

    std::cout << "encoded:   " << rest2_encoded << std::endl;
    std::cout << "reference: " << rest2_reference << std::endl;
    std::cout << "decoded:   " << rest2_decoded << std::endl << std::endl;

    std::string rest3_encoded = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCAuLi4=";
    std::string rest3_decoded = base64_decode(rest3_encoded);

    std::cout << "encoded:   " << rest3_encoded << std::endl;
    std::cout << "decoded:   " << rest3_decoded << std::endl << std::endl;

    std::string example_encoded =
        "QJKPXECHvndAgMScQHul40CSLQ5ArocrQLxiTkC3XClAq0OWQKQIMUCblYFAh753QGij10BT\n"
        "    Em9ARKwIQExqf0BqbphAieuFQJS0OUCJWBBAhcrBQJMzM0CmRaJAuRaHQLWZmkCyhytAunbJ\n"
        "    QLN87kC26XlA1KwIQOu+d0DsWh1A5an8QN0m6UDOVgRAxO2RQM9Lx0Din75A3o9cQMPfO0C/\n"
        "    dLxAvUeuQKN87kCXQ5ZAjFodQH0vG0B/jVBAgaHLQI7Ag0CiyLRAqBBiQLaXjUDYcrBA8p++\n"
        "    QPcKPUDg7ZFAwcKPQLafvkDDlYFA1T99QM2BBkCs3S9AjLxqQISDEkCO6XlAmlYEQKibpkC5\n"
        "    wo9AvKPXQLGBBkCs9cNAuGp/QL0euEC4crBAuR64QL6PXEDOTdNA2987QN9T+EDoMSdA8mZm\n"
        "    QOZumEDDZFpAmmZmQGlYEEBa4UhAivGqQLel40Dgan9A4WBCQLNcKUCIKPZAk1P4QNWRaEEP\n"
        "    kWhBKaHLQTkOVkFEan9BUWBCQVyfvg==";

    std::string example_decoded = base64_decode(example_encoded);
    std::cout << "votable_encoded: " << example_encoded << std::endl;
    std::cout << "votable_decoded: " << example_decoded << ", string length: " << strlen(example_decoded.c_str()) << std::endl;

    float f;
    // char b[] = {example_decoded.c_str()[3], example_decoded.c_str()[2], example_decoded.c_str()[1], example_decoded.c_str()[0]};
    // char b[] = {example_decoded.c_str()[7], example_decoded.c_str()[6], example_decoded.c_str()[5], example_decoded.c_str()[4]};
    // char b[] = {example_decoded.c_str()[11], example_decoded.c_str()[10], example_decoded.c_str()[9], example_decoded.c_str()[8]};
    // char b[] = {example_decoded.c_str()[15], example_decoded.c_str()[14], example_decoded.c_str()[13], example_decoded.c_str()[12]};
    // char b[] = {example_decoded.c_str()[19], example_decoded.c_str()[18], example_decoded.c_str()[17], example_decoded.c_str()[16]};
    // char b[] = {example_decoded.c_str()[23], example_decoded.c_str()[22], example_decoded.c_str()[21], example_decoded.c_str()[20]};
    // char b[] = {example_decoded.c_str()[47], example_decoded.c_str()[46], example_decoded.c_str()[45], example_decoded.c_str()[44]};
    // char b[] = {example_decoded.c_str()[51], example_decoded.c_str()[50], example_decoded.c_str()[49], example_decoded.c_str()[48]};
    char b[] = {example_decoded.c_str()[55], example_decoded.c_str()[54], example_decoded.c_str()[53], example_decoded.c_str()[52]};

    // char b[] = {example_decoded.c_str()[59], example_decoded.c_str()[58], example_decoded.c_str()[57], example_decoded.c_str()[56]};
    // char b[] = {example_decoded.c_str()[63], example_decoded.c_str()[62], example_decoded.c_str()[61], example_decoded.c_str()[60]};

    memcpy(&f, &b, sizeof(f));
    std::cout << "f= " << f << std::endl << std::endl;

    std::string example_encoded2 = "AAAAAj/yVZiDGSSUwFZ6ypR4yGkADwAcQV0euAAIAAJBmMzNwZWZmkGle4tBR3jVQT9ocwAA";

    std::string example_decoded2 = base64_decode(example_encoded2);
    std::cout << "votable_encoded2: " << example_encoded2 << std::endl;
    std::cout << "votable_decoded2: " << example_decoded2 << ", string length2: " << strlen(example_decoded2.c_str()) << std::endl;

    short f2;
    char b2[] = {example_decoded2.c_str()[3], example_decoded2.c_str()[2], example_decoded2.c_str()[1], example_decoded2.c_str()[0]};
    memcpy(&f2, &b2, sizeof(f2));
    std::cout << "f2= " << f2 << std::endl << std::endl;

    return 0;
}
