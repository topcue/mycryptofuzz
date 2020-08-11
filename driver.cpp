#include "driver.h"
#include <fuzzing/datasource/id.hpp>
#include "tests.h"
#include "executor.h"
#include <cryptofuzz/util.h>
#include <set>
#include <algorithm>
#include <unistd.h>

// my
#include <iostream>
namespace cryptofuzz {

void Driver::LoadModule(std::shared_ptr<Module> module) {
    modules[module->ID] = module;
}

void Driver::Run(const uint8_t* data, const size_t size) const {
    using fuzzing::datasource::ID;

	// my
#if 1
	static ExecutorPEM_READ executorPEM_READ(CF_OPERATION("PEM_READ"), modules, options);
	static ExecutorNEW_OP executorNEW_OP(CF_OPERATION("NEW_OP"), modules, options);
#endif
    static ExecutorDigest executorDigest(CF_OPERATION("Digest"), modules, options);
    static ExecutorHMAC executorHMAC(CF_OPERATION("HMAC"), modules, options);
    static ExecutorCMAC executorCMAC(CF_OPERATION("CMAC"), modules, options);
    static ExecutorSymmetricEncrypt executorSymmetricEncrypt(CF_OPERATION("SymmetricEncrypt"), modules, options);
    static ExecutorSymmetricDecrypt executorSymmetricDecrypt(CF_OPERATION("SymmetricDecrypt"), modules, options);
    static ExecutorKDF_SCRYPT executorKDF_SCRYPT(CF_OPERATION("KDF_SCRYPT"), modules, options);
    static ExecutorKDF_HKDF executorKDF_HKDF(CF_OPERATION("KDF_HKDF"), modules, options);
    static ExecutorKDF_TLS1_PRF executorKDF_TLS1_PRF(CF_OPERATION("KDF_TLS1_PRF"), modules, options);
    static ExecutorKDF_PBKDF executorKDF_PBKDF(CF_OPERATION("KDF_PBKDF"), modules, options);
    static ExecutorKDF_PBKDF1 executorKDF_PBKDF1(CF_OPERATION("KDF_PBKDF1"), modules, options);
    static ExecutorKDF_PBKDF2 executorKDF_PBKDF2(CF_OPERATION("KDF_PBKDF2"), modules, options);
    static ExecutorKDF_ARGON2 executorKDF_ARGON2(CF_OPERATION("KDF_ARGON2"), modules, options);
    static ExecutorKDF_SSH executorKDF_SSH(ID("Cryptofuzz/Operation/KDF_SSH"), modules, options);
    static ExecutorKDF_X963 executorKDF_X963(CF_OPERATION("KDF_X963"), modules, options);
    static ExecutorKDF_BCRYPT executorKDF_BCRYPT(CF_OPERATION("KDF_BCRYPT"), modules, options);
    static ExecutorKDF_SP_800_108 executorKDF_SP_800_108(CF_OPERATION("KDF_SP_800_108"), modules, options);
    static ExecutorECC_PrivateToPublic executorECC_PrivateToPublic(CF_OPERATION("ECC_PrivateToPublic"), modules, options);
    static ExecutorECC_GenerateKeyPair executorECC_GenerateKeyPair(CF_OPERATION("ECC_GenerateKeyPair"), modules, options);
    static ExecutorECDSA_Sign executorECDSA_Sign(CF_OPERATION("ECDSA_Sign"), modules, options);
    static ExecutorECDSA_Verify executorECDSA_Verify(CF_OPERATION("ECDSA_Verify"), modules, options);
    static ExecutorECDH_Derive executorECDH_Derive(CF_OPERATION("ECDH_Derive"), modules, options);
    static ExecutorBignumCalc executorBignumCalc(CF_OPERATION("BignumCalc"), modules, options);

    try {

        Datasource ds(data, size);

        const auto operation = ds.Get<uint64_t>();

        /* Only run whitelisted operations, if specified */
        if ( options.operations != std::nullopt ) {
            if ( std::find(
                    options.operations->begin(),
                    options.operations->end(),
                    operation) == options.operations->end() ) {
                return;
            }
        }
        const auto payload = ds.GetData(0, 1);

        switch ( operation ) {
			// my
#if 0
			case CF_OPERATION("PEM_READ"):
				std::cout << "CF_OPERATION("PEM_READ")" << std::endl;
				executorPEM_READ.Run(ds, payload.data(), payload.size());
				break;
			case CF_OPERATION("NEW_OP"):
				std::cout << CF_OPERATION("NEW_OP") << std::endl;
				executorNEW_OP.Run(ds, payload.data(), payload.size());
				break;
#endif
            case CF_OPERATION("Digest"):
                executorDigest.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("HMAC"):
                executorHMAC.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("CMAC"):
                executorCMAC.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("SymmetricEncrypt"):
                executorSymmetricEncrypt.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("SymmetricDecrypt"):
                executorSymmetricDecrypt.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_SCRYPT"):
                executorKDF_SCRYPT.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_HKDF"):
                executorKDF_HKDF.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_TLS1_PRF"):
                executorKDF_TLS1_PRF.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_PBKDF"):
                executorKDF_PBKDF.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_PBKDF1"):
                executorKDF_PBKDF1.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_PBKDF2"):
                executorKDF_PBKDF2.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_ARGON2"):
                executorKDF_ARGON2.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_SSH"):
                executorKDF_SSH.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_X963"):
                executorKDF_X963.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_BCRYPT"):
                executorKDF_BCRYPT.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("KDF_SP_800_108"):
                executorKDF_SP_800_108.Run(ds, payload.data(), payload.size());
                break;
#if 0
            case    ID("Cryptofuzz/Operation/Sign"):
                executorSign.Run(ds, payload.data(), payload.size());
                break;
            case    ID("Cryptofuzz/Operation/Verify"):
                executorVerify.Run(ds, payload.data(), payload.size());
                break;
#endif
            case CF_OPERATION("ECC_PrivateToPublic"):
                executorECC_PrivateToPublic.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("ECC_GenerateKeyPair"):
                executorECC_GenerateKeyPair.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("ECDSA_Sign"):
                executorECDSA_Sign.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("ECDSA_Verify"):
                executorECDSA_Verify.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("ECDH_Derive"):
                executorECDH_Derive.Run(ds, payload.data(), payload.size());
                break;
            case CF_OPERATION("BignumCalc"):
                executorBignumCalc.Run(ds, payload.data(), payload.size());
                break;
        }
    } catch ( Datasource::OutOfData ) {
    }
};

Driver::Driver(const Options options) :
    options(options)
{ }

} /* namespace cryptofuzz */
