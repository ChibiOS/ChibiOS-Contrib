# ANJAY files.

AVS_COMMONS = $(CHIBIOS_CONTRIB)/ext/avs_commons-5.4.1
ANJAY = $(CHIBIOS_CONTRIB)/ext/Anjay-3.5.0
ANJAY_COAP = $(ANJAY)/deps/avs_coap
ANJAY_BINDINGS=$(CHIBIOS_CONTRIB)/os/various/anjay_bindings

ANJAYSRC = \
           $(ANJAY_BINDINGS)/compat/threading/avs_cmsis_os_condvar.c \
           $(ANJAY_BINDINGS)/compat/threading/avs_cmsis_os_init_once.c \
           $(ANJAY_BINDINGS)/compat/threading/avs_csmis_os_mutex.c \
           $(ANJAY_BINDINGS)/compat/stdlib/avs_memory_chibios.c \
           $(ANJAY_BINDINGS)/compat/stdlib/avs_time_chibios.c \
           $(ANJAY_BINDINGS)/compat/stdlib/avs_math_chibios.c \
           $(AVS_COMMONS)/src/algorithm/avs_base64.c \
           $(AVS_COMMONS)/src/buffer/avs_buffer.c \
           $(AVS_COMMONS)/src/crypto/generic/avs_generic_prng.c \
           $(AVS_COMMONS)/src/crypto/mbedtls/avs_mbedtls_aead.c \
           $(AVS_COMMONS)/src/crypto/mbedtls/avs_mbedtls_data_loader.c \
           $(AVS_COMMONS)/src/crypto/mbedtls/avs_mbedtls_global.c \
           $(AVS_COMMONS)/src/crypto/mbedtls/avs_mbedtls_hkdf.c \
           $(AVS_COMMONS)/src/crypto/mbedtls/avs_mbedtls_pki.c \
           $(AVS_COMMONS)/src/crypto/mbedtls/avs_mbedtls_private.c \
           $(AVS_COMMONS)/src/crypto/mbedtls/avs_mbedtls_prng.c \
           $(AVS_COMMONS)/src/crypto/avs_crypto_global.c \
           $(AVS_COMMONS)/src/crypto/avs_crypto_persistence.c \
           $(AVS_COMMONS)/src/crypto/avs_crypto_utils.c \
           $(AVS_COMMONS)/src/list/avs_list.c \
           $(AVS_COMMONS)/src/log/avs_log.c \
           $(AVS_COMMONS)/src/net/mbedtls/avs_mbedtls_persistence.c \
           $(AVS_COMMONS)/src/net/mbedtls/avs_mbedtls_socket.c \
           $(AVS_COMMONS)/src/net/tinydtls/avs_tinydtls.c \
           $(AVS_COMMONS)/src/net/avs_addrinfo.c \
           $(AVS_COMMONS)/src/net/avs_api.c \
           $(AVS_COMMONS)/src/net/avs_net_global.c \
           $(AVS_COMMONS)/src/persistence/avs_persistence.c \
           $(AVS_COMMONS)/src/rbtree/avs_rbtree.c \
           $(AVS_COMMONS)/src/sched/avs_sched.c \
           $(AVS_COMMONS)/src/sorted_set/avs_sorted_set.c \
           $(AVS_COMMONS)/src/stream/avs_stream.c \
           $(AVS_COMMONS)/src/stream/avs_stream_buffered.c \
           $(AVS_COMMONS)/src/stream/avs_stream_common.c \
           $(AVS_COMMONS)/src/stream/avs_stream_file.c \
           $(AVS_COMMONS)/src/stream/avs_stream_inbuf.c \
           $(AVS_COMMONS)/src/stream/avs_stream_membuf.c \
           $(AVS_COMMONS)/src/stream/avs_stream_simple_io.c \
           $(AVS_COMMONS)/src/stream/md5/avs_md5_common.c \
           $(AVS_COMMONS)/src/stream/md5/avs_md5_impl.c \
           $(AVS_COMMONS)/src/stream/net/avs_netbuf.c \
           $(AVS_COMMONS)/src/stream/net/avs_stream_net.c \
           $(AVS_COMMONS)/src/url/avs_url.c \
           $(AVS_COMMONS)/src/utils/avs_cleanup.c \
           $(AVS_COMMONS)/src/utils/avs_hexlify.c \
           $(AVS_COMMONS)/src/utils/avs_numbers.c \
           $(AVS_COMMONS)/src/utils/avs_shared_buffer.c \
           $(AVS_COMMONS)/src/utils/avs_strerror.c \
           $(AVS_COMMONS)/src/utils/avs_strings.c \
           $(AVS_COMMONS)/src/utils/avs_time.c \
           $(AVS_COMMONS)/src/utils/avs_token.c \
           $(AVS_COMMONS)/src/vector/avs_vector.c \
           $(ANJAY)/src/core/io/cbor/anjay_cbor_encoder_ll.c \
           $(ANJAY)/src/core/io/cbor/anjay_json_like_cbor_decoder.c \
           $(ANJAY)/src/core/io/json/anjay_json_decoder.c \
           $(ANJAY)/src/core/io/anjay_base64_out.c \
           $(ANJAY)/src/core/io/anjay_batch_builder.c \
           $(ANJAY)/src/core/io/anjay_cbor_in.c \
           $(ANJAY)/src/core/io/anjay_cbor_out.c \
           $(ANJAY)/src/core/io/anjay_common.c \
           $(ANJAY)/src/core/io/anjay_dynamic.c \
           $(ANJAY)/src/core/io/anjay_input_buf.c \
           $(ANJAY)/src/core/io/anjay_json_encoder.c \
           $(ANJAY)/src/core/io/anjay_json_like_decoder.c \
           $(ANJAY)/src/core/io/anjay_opaque.c \
           $(ANJAY)/src/core/io/anjay_output_buf.c \
           $(ANJAY)/src/core/io/anjay_senml_in.c \
           $(ANJAY)/src/core/io/anjay_senml_like_encoder.c \
           $(ANJAY)/src/core/io/anjay_senml_like_out.c \
           $(ANJAY)/src/core/io/anjay_text.c \
           $(ANJAY)/src/core/io/anjay_tlv_in.c \
           $(ANJAY)/src/core/io/anjay_tlv_out.c \
           $(ANJAY_COAP)/src/avs_coap_code_utils.c \
           $(ANJAY_COAP)/src/avs_coap_common_utils.c \
           $(ANJAY_COAP)/src/avs_coap_ctx.c \
           $(ANJAY_COAP)/src/async/avs_coap_async_client.c \
           $(ANJAY_COAP)/src/async/avs_coap_async_server.c \
           $(ANJAY_COAP)/src/async/avs_coap_exchange.c \
           $(ANJAY_COAP)/src/options/avs_coap_iterator.c \
           $(ANJAY_COAP)/src/options/avs_coap_option.c \
           $(ANJAY_COAP)/src/options/avs_coap_options.c \
           $(ANJAY_COAP)/src/streaming/avs_coap_streaming_client.c \
           $(ANJAY_COAP)/src/streaming/avs_coap_streaming_server.c \
           $(ANJAY_COAP)/src/tcp/avs_coap_tcp_ctx.c \
           $(ANJAY_COAP)/src/tcp/avs_coap_tcp_header.c \
           $(ANJAY_COAP)/src/tcp/avs_coap_tcp_msg.c \
           $(ANJAY_COAP)/src/tcp/avs_coap_tcp_pending_requests.c \
           $(ANJAY_COAP)/src/tcp/avs_coap_tcp_signaling.c \
           $(ANJAY_COAP)/src/tcp/avs_coap_tcp_utils.c \
           $(ANJAY_COAP)/src/udp/avs_coap_udp_ctx.c \
           $(ANJAY_COAP)/src/udp/avs_coap_udp_msg.c \
           $(ANJAY_COAP)/src/udp/avs_coap_udp_msg_cache.c \
           $(ANJAY_COAP)/src/udp/avs_coap_udp_tx_params.c \
           $(AVS_COMMONS)/src/net/compat/posix/avs_compat_addrinfo.c \
           $(AVS_COMMONS)/src/net/compat/posix/avs_inet_ntop.c

ifeq ($(USE_LWIP),yes)
ANJAYSRC += \
		$(AVS_COMMONS)/src/net/compat/posix/avs_net_impl.c
else
ANJAYSRC += \
		$(ANJAY_BINDINGS)/compat/net/xcc_wiznet_sockets_net_impl.c
endif

ANJAYINC = \
           $(ANJAY_BINDINGS) \
           $(ANJAY_BINDINGS)/compat/net \
           $(ANJAY_BINDINGS)/compat/threading \
           $(ANJAY_BINDINGS)/compat/stdlib \
           $(AVS_COMMONS)/include_public \
           $(AVS_COMMONS) \
           $(AVS_COMMONS)/src \
           $(AVS_COMMONS)/src/net \
           $(AVS_COMMONS)/src/net/compat/posix \
           $(AVS_COMMONS)/src/net/mbedtls \
           $(AVS_COMMONS)/src/crypto \
           $(AVS_COMMONS)/src/crypto/mbedtls \
           $(AVS_COMMONS)/src/stream \
           $(AVS_COMMONS)/src/stream/md5 \
           $(ANJAY)/include_public \
           $(ANJAY)/src/core/io/cbor \
           $(ANJAY)/src/core/io/json \
           $(ANJAY)/src/core/io \
           $(ANJAY)/src \
           $(ANJAY_COAP)/include_public \
           $(ANJAY_COAP)/src \
           $(ANJAY_COAP)/src/async \
           $(ANJAY_COAP)/src/options \
           $(ANJAY_COAP)/src/streaming \
           $(ANJAY_COAP)/src/tcp \
           $(ANJAY_COAP)/src/udp

# Shared variables
ALLCSRC += $(ANJAYSRC)
ALLINC  += $(ANJAYINC)
