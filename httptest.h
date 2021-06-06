//
// Created by 22696 on 2021/6/6.
//

#ifndef UNTITLED3_HTTPTEST_H
#define UNTITLED3_HTTPTEST_H

#include <httplib.h>

class httptest {
public:
    const void test() {
        httplib::Headers headers = {
                {"Authorization", "eyJhbGciOiJIUzUxMiJ9.eyJsb2dpbl91c2VyX2tleSI6ImRkM2Q4MjE5LWU4NmUtNDk2Ny1hMTBlLTVmNjcwOWU4Nzc3NyJ9.X8ylMdAJPKv5ZUkbSomXoJFqDwVf-hfLTaCX6me9b2oDKyfLsBAVmo9oHIN2HofWf_bdM-bLbEkK11042vtynw"}
        };
        httplib::Client cli("101.200.79.90", 80);
        if (auto res = cli.Get("/prod-api/system/user/list?pageNum=1&pageSize=10",headers)) {
            if (res->status == 200) {
                std::cout << res->body << std::endl;
            }
        } else {
            auto err = res.error();
            std::cout << "err" << std::endl;
        }
    }

};


#endif //UNTITLED3_HTTPTEST_H
