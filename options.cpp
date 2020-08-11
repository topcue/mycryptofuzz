#include <cryptofuzz/options.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>
#include <stdlib.h>
#include <cryptofuzz/repository.h>

// my
#include <iostream>
#include <iomanip>

namespace cryptofuzz {

	Options::Options(const int argc, char** argv) {
		for (int i = 0; i < argc; i++) {
			arguments.push_back( std::string(argv[i]) );
		}

		for (size_t i = 1; i < arguments.size(); i++) {
			const auto arg = arguments[i];
			std::vector<std::string> parts;
			boost::split(parts, arg, boost::is_any_of("="));

			if ( arg == "--debug" ) {
				// my
				std::cout << "[*] OPTION : DEBUG" << std::endl;

				debug = true;
			}
			// my : show available options
			else if (!parts.empty() && parts[0] == "--available") {
				std::cout << "[*] OPTION : AVAILABLE" << std::endl;

				std::cout << "[*] Available operations" << std::endl;
				for (size_t i = 0; i < (sizeof(repository::OperationLUT) / sizeof(repository::OperationLUT[0])); i++) {
					std::cout << repository::OperationLUT[i].name << "   ";
				}
				std::cout << std::endl;

				std::cout << "[*] Available modules" << std::endl;
				for (size_t i = 0; i < (sizeof(repository::ModuleLUT) / sizeof(repository::ModuleLUT[0])); i++) {
					std::cout << repository::ModuleLUT[i].name << "   ";
				}
				std::cout << std::endl;

				exit(1);
			} else if ( !parts.empty() && parts[0] == "--operations" ) {
				if ( parts.size() != 2 ) {
					std::cout << "Expected argument after --operations=" << std::endl;
					exit(1);
				}

				std::vector<std::string> operationStrings;
				boost::split(operationStrings, parts[1], boost::is_any_of(","));

				std::vector<uint64_t> operationIDs;

				// my
				std::cout << "[*] OPTION : OPERATION" << std::endl;

				for (const auto& curOpStr : operationStrings) {
					bool found = false;
					for (size_t i = 0; i < (sizeof(repository::OperationLUT) / sizeof(repository::OperationLUT[0])); i++) {
						if ( boost::iequals(curOpStr, std::string(repository::OperationLUT[i].name)) ) {
							// my
							std::cout << "[" << repository::OperationLUT[i].name << "]" << std::endl;

							operationIDs.push_back(repository::OperationLUT[i].id);
							found = true;
							break;
						}
					}

					if ( found == false ) {
						std::cout << "Undefined operation: " << curOpStr << std::endl;
						exit(1);
					}
				}

				this->operations = operationIDs;
			} else if ( !parts.empty() && parts[0] == "--force-module" ) {
				if ( parts.size() != 2 ) {
					std::cout << "Expected argument after --operations=" << std::endl;
					exit(1);
				}

				const auto& moduleStr = parts[1];

				bool found = false;
				uint64_t forceModule;
				// my
				std::cout << "[*] OPTION : MODULE" << std::endl;

				for (size_t i = 0; i < (sizeof(repository::ModuleLUT) / sizeof(repository::ModuleLUT[0])); i++) {
					if ( boost::iequals(moduleStr, std::string(repository::ModuleLUT[i].name)) ) {
						// my
						std::cout << "[" << repository::ModuleLUT[i].name << "]" << std::endl;

						forceModule = repository::ModuleLUT[i].id;
						found = true;
						break;
					}
				}

				if ( found == false ) {
					std::cout << "Undefined module: " << moduleStr << std::endl;
					exit(1);
				}

				this->forceModule = forceModule;
			}
		}
		std::cout << "\n\n" << std::endl;
	}

} /* namespace cryptofuzz */


