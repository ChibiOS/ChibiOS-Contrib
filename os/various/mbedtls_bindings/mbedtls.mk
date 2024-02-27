MBEDTLS = $(CHIBIOS_CONTRIB)/ext/mbedtls-mbedtls-3.5.0

MBEDBINDSRC = \
        $(CHIBIOS_CONTRIB)/os/various/mbedtls_bindings/mbedtls_rng.c \
        $(CHIBIOS_CONTRIB)/os/various/mbedtls_bindings/mbedtls_timing.c \
        $(MBEDTLS)/library/aes.c \
        $(MBEDTLS)/library/aesce.c \
        $(MBEDTLS)/library/aesni.c \
        $(MBEDTLS)/library/aria.c \
        $(MBEDTLS)/library/asn1parse.c \
        $(MBEDTLS)/library/asn1write.c \
        $(MBEDTLS)/library/base64.c \
        $(MBEDTLS)/library/bignum.c \
        $(MBEDTLS)/library/bignum_core.c \
        $(MBEDTLS)/library/bignum_mod.c \
        $(MBEDTLS)/library/bignum_mod_raw.c \
        $(MBEDTLS)/library/camellia.c \
        $(MBEDTLS)/library/ccm.c \
        $(MBEDTLS)/library/chacha20.c \
        $(MBEDTLS)/library/chachapoly.c \
        $(MBEDTLS)/library/cipher.c \
        $(MBEDTLS)/library/cipher_wrap.c \
        $(MBEDTLS)/library/cmac.c \
        $(MBEDTLS)/library/constant_time.c \
        $(MBEDTLS)/library/debug.c \
        $(MBEDTLS)/library/des.c \
        $(MBEDTLS)/library/dhm.c \
        $(MBEDTLS)/library/ecdh.c \
        $(MBEDTLS)/library/ecdsa.c \
        $(MBEDTLS)/library/ecjpake.c \
        $(MBEDTLS)/library/ecp.c \
        $(MBEDTLS)/library/ecp_curves.c \
        $(MBEDTLS)/library/ecp_curves_new.c \
        $(MBEDTLS)/library/error.c \
        $(MBEDTLS)/library/gcm.c \
        $(MBEDTLS)/library/hkdf.c \
        $(MBEDTLS)/library/hmac_drbg.c \
        $(MBEDTLS)/library/lmots.c \
        $(MBEDTLS)/library/lms.c \
        $(MBEDTLS)/library/md.c \
        $(MBEDTLS)/library/md5.c \
        $(MBEDTLS)/library/memory_buffer_alloc.c \
        $(MBEDTLS)/library/mps_reader.c \
        $(MBEDTLS)/library/mps_trace.c \
        $(MBEDTLS)/library/nist_kw.c \
        $(MBEDTLS)/library/oid.c \
        $(MBEDTLS)/library/padlock.c \
        $(MBEDTLS)/library/pem.c \
        $(MBEDTLS)/library/pk.c \
        $(MBEDTLS)/library/pk_wrap.c \
        $(MBEDTLS)/library/pkcs12.c \
        $(MBEDTLS)/library/pkcs5.c \
        $(MBEDTLS)/library/pkcs7.c \
        $(MBEDTLS)/library/pkparse.c \
        $(MBEDTLS)/library/pkwrite.c \
        $(MBEDTLS)/library/platform.c \
        $(MBEDTLS)/library/platform_util.c \
        $(MBEDTLS)/library/poly1305.c \
        $(MBEDTLS)/library/psa_crypto.c \
        $(MBEDTLS)/library/psa_crypto_aead.c \
        $(MBEDTLS)/library/psa_crypto_cipher.c \
        $(MBEDTLS)/library/psa_crypto_client.c \
        $(MBEDTLS)/library/psa_crypto_driver_wrappers_no_static.c \
        $(MBEDTLS)/library/psa_crypto_ecp.c \
        $(MBEDTLS)/library/psa_crypto_ffdh.c \
        $(MBEDTLS)/library/psa_crypto_hash.c \
        $(MBEDTLS)/library/psa_crypto_mac.c \
        $(MBEDTLS)/library/psa_crypto_pake.c \
        $(MBEDTLS)/library/psa_crypto_rsa.c \
        $(MBEDTLS)/library/psa_crypto_se.c \
        $(MBEDTLS)/library/psa_crypto_slot_management.c \
        $(MBEDTLS)/library/psa_crypto_storage.c \
        $(MBEDTLS)/library/psa_its_file.c \
        $(MBEDTLS)/library/psa_util.c \
        $(MBEDTLS)/library/ripemd160.c \
        $(MBEDTLS)/library/rsa.c \
        $(MBEDTLS)/library/rsa_alt_helpers.c \
        $(MBEDTLS)/library/sha1.c \
        $(MBEDTLS)/library/sha256.c \
        $(MBEDTLS)/library/sha3.c \
        $(MBEDTLS)/library/sha512.c \
        $(MBEDTLS)/library/ssl_cache.c \
        $(MBEDTLS)/library/ssl_ciphersuites.c \
        $(MBEDTLS)/library/ssl_client.c \
        $(MBEDTLS)/library/ssl_cookie.c \
        $(MBEDTLS)/library/ssl_debug_helpers_generated.c \
        $(MBEDTLS)/library/ssl_msg.c \
        $(MBEDTLS)/library/ssl_ticket.c \
        $(MBEDTLS)/library/ssl_tls.c \
        $(MBEDTLS)/library/ssl_tls12_client.c \
        $(MBEDTLS)/library/ssl_tls12_server.c \
        $(MBEDTLS)/library/ssl_tls13_client.c \
        $(MBEDTLS)/library/ssl_tls13_generic.c \
        $(MBEDTLS)/library/ssl_tls13_keys.c \
        $(MBEDTLS)/library/ssl_tls13_server.c \
        $(MBEDTLS)/library/threading.c \
        $(MBEDTLS)/library/version.c \
        $(MBEDTLS)/library/x509.c \
        $(MBEDTLS)/library/x509_create.c \
        $(MBEDTLS)/library/x509_crl.c \
        $(MBEDTLS)/library/x509_crt.c \
        $(MBEDTLS)/library/x509_csr.c \
        $(MBEDTLS)/library/x509write.c \
        $(MBEDTLS)/library/x509write_crt.c \
        $(MBEDTLS)/library/x509write_csr.c

MBEDBINDINC  = \
        $(MBEDTLS)/include

# Shared variables
ALLCSRC += $(MBEDBINDSRC)
ALLINC  += $(MBEDBINDINC)
