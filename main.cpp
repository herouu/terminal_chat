#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include "httptest.h"

using namespace std;

int main(int argc, char *argv[]) {
    using namespace boost::program_options;
    httptest httpt;
    //声明需要的选项
    options_description desc("Allowed options");
    desc.add_options()
            ("help,h", "produce help message")
            ("person,p", value<string>()->default_value("world"), "who");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help")) {
        cout << desc;
        return 0;
    }
    httpt.test();
    cout << "Hello " << vm["person"].as<string>() << endl;
    return 0;
}