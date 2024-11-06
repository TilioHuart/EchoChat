
// doc :    https://www.gnupg.org/documentation/manuals/gpgme/


#include <gpgme.h>
#include <iostream>
#include <string>

void generate_and_print_gpg_keys(const std::string& name, const std::string& email) {
    gpgme_error_t gpg_err;
    gpgme_ctx_t ctx;
    gpgme_genkey_result_t result;

    // GPG context creation (ctx = context) | doc ref { 7.1 Creating Contexts }
    gpgme_check_version(nullptr);
    gpgme_new(&ctx);

    // key parameters | doc ref { 7.1 Creating Contexts }
    std::string key_params = "<GnupgKeyParms format=\"internal\">\n";
    key_params += "Key-Type: RSA\n";
    key_params += "Key-Length: 2048\n";
    key_params += "Name-Real: " + name + "\n";
    key_params += "Name-Email: " + email + "\n";
    key_params += "Expire-Date: 1y\n";
    key_params += "</GnupgKeyParms>\n";

    // Generate a key pair in the context | doc ref { 7.5.5 Generating keys }
    gpg_err = gpgme_op_genkey(ctx, key_params.c_str(), nullptr, nullptr);
    if (gpg_err) {
        std::cerr << "Error generating key: " << gpgme_strerror(gpg_err) << std::endl;
        return;
    }

    result = gpgme_op_genkey_result(ctx);
    if (!result || !result->fpr) {
        std::cerr << "Error: No fingerprint available for generated key." << std::endl;
        return;
    }

    std::cout << "Generated key with fingerprint: " << result->fpr << std::endl;

    // Export (and print) the public key | doc ref { 7.5.7 Exporting Keys }
    gpgme_data_t keydata;
    gpgme_data_new(&keydata);
    gpg_err = gpgme_op_export(ctx, result->fpr, GPGME_EXPORT_MODE_MINIMAL, keydata);
    if (gpg_err) {
        std::cerr << "Error exporting key: " << gpgme_strerror(gpg_err) << std::endl;
    } else {
        std::string key_output;
        char buffer[1024];
        ssize_t nread;
        gpgme_data_seek(keydata, 0, SEEK_SET);
        while ((nread = gpgme_data_read(keydata, buffer, sizeof(buffer))) > 0) {
            key_output.append(buffer, nread);
        }
        if (key_output.empty()) {
            std::cerr << "Exported key data is empty." << std::endl;
        } else {
            std::cout << "Public Key:\n" << key_output;
        }
    }

    // List all Keys | doc ref { 7.5.2 Listing Keys }
    gpgme_op_keylist_start(ctx, NULL, 0);

    // Release data | doc ref { 6.2 Destroying Data Buffers }
    gpgme_data_release(keydata);
    gpgme_release(ctx);
}
