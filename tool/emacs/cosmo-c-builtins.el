(defconst cosmo-c-builtins-regex
  (let (

        (c11
         '("static_assert"))

        (gcc-cpp-92-builtin-defines
         '("__VA_OPT__"
           "__COUNTER__"
           "__SIG_ATOMIC_TYPE__"
           "__INT8_TYPE__"
           "__INT16_TYPE__"
           "__INT32_TYPE__"
           "__INT64_TYPE__"
           "__UINT8_TYPE__"
           "__UINT16_TYPE__"
           "__UINT32_TYPE__"
           "__UINT64_TYPE__"
           "__INT_LEAST8_TYPE__"
           "__INT_LEAST16_TYPE__"
           "__INT_LEAST32_TYPE__"
           "__INT_LEAST64_TYPE__"
           "__UINT_LEAST8_TYPE__"
           "__UINT_LEAST16_TYPE__"
           "__UINT_LEAST32_TYPE__"
           "__UINT_LEAST64_TYPE__"
           "__INT_FAST8_TYPE__"
           "__INT_FAST16_TYPE__"
           "__INT_FAST32_TYPE__"
           "__INT_FAST64_TYPE__"
           "__UINT_FAST8_TYPE__"
           "__UINT_FAST16_TYPE__"
           "__UINT_FAST32_TYPE__"
           "__UINT_FAST64_TYPE__"
           "__INTPTR_TYPE__"
           "__UINTPTR_TYPE__"
           "__TIMESTAMP__"
           "__SANITIZE_ADDRESS__"
           "__SANITIZE_UNDEFINED__"
           "__FP_FAST_FMA"
           "__FP_FAST_FMAF"
           "__FP_FAST_FMAL"))

        (gcc-builtin-types
         '("__builtin_va_list"))

        (gcc-builtin-functions
         '("__builtin_strlen"
           "__builtin_setjmp"
           "__builtin_longjmp"
           "__builtin_va_start"
           "__builtin_va_arg"
           "__builtin_va_end"
           "__builtin_add_overflow"
           "__builtin_add_overflow_p"
           "__builtin_alloc"
           "__builtin_alloca"
           "__builtin_alloca_with_align"
           "__builtin_alloca_with_align_and_max"
           "__builtin_apply"
           "__builtin_apply_args"
           "__builtin_assume"
           "__builtin_assume_aligned"
           "__builtin_bswap16"
           "__builtin_bswap32"
           "__builtin_bswap64"
           "__builtin_call_with_static_chain"
           "__builtin_choose_expr"
           "__builtin_clz"
           "__builtin_clzl"
           "__builtin_clzll"
           "__builtin_constant_p"
           "__builtin_ctz"
           "__builtin_ctzl"
           "__builtin_ctzll"
           "__builtin_expect"
           "__builtin_memcpy"
           "__builtin_memset"
           "__builtin_expect_with_probability"
           "__builtin_extract_return_addr"
           "__builtin_isnan"
           "__builtin_signbit"
           "__builtin_signbitf"
           "__builtin_signbitl"
           "__builtin_ffs"
           "__builtin_ffsl"
           "__builtin_ffsll"
           "__builtin_fma"
           "__builtin_fpclassify"
           "__builtin_frame_address"
           "__builtin_frob_return_addr"
           "__builtin_has_attribute"
           "__builtin_mul_overflow"
           "__builtin_mul_overflow_p"
           "__builtin_object_size"
           "__builtin_offsetof"
           "__builtin_popcount"
           "__builtin_popcountl"
           "__builtin_popcountll"
           "__builtin_prefetch"
           "__builtin_return"
           "__builtin_return_address"
           "__builtin_sub_overflow"
           "__builtin_sub_overflow_p"
           "__builtin_trap"
           "__builtin_types_compatible_p"
           "__builtin_unreachable"
           "__builtin_ia32_movntdq"
           "__has_attribute"
           "__has_builtin"
           "__has_include"
           "__has_cpp_attribute"
           "__has_feature"
           "__ATOMIC_RELAXED"
           "__ATOMIC_CONSUME"
           "__ATOMIC_ACQUIRE"
           "__ATOMIC_RELEASE"
           "__ATOMIC_ACQ_REL"
           "__ATOMIC_SEQ_CST"))

        (gcc-builtin-functions-atomic
         '("__atomic_load_n"
           "__atomic_load"
           "__atomic_store"
           "__atomic_store_n"
           "__atomic_exchange_n"
           "__atomic_exchange"
           "__atomic_compare_exchange_n"
           "__atomic_compare_exchange"
           "__atomic_add_fetch"
           "__atomic_sub_fetch"
           "__atomic_and_fetch"
           "__atomic_xor_fetch"
           "__atomic_or_fetch"
           "__atomic_nand_fetch"
           "__atomic_fetch_add"
           "__atomic_fetch_sub"
           "__atomic_fetch_and"
           "__atomic_fetch_xor"
           "__atomic_fetch_or"
           "__atomic_fetch_nand"
           "__atomic_test_and_set"
           "__atomic_clear"
           "__atomic_thread_fence"
           "__atomic_signal_fence"
           "__atomic_always_lock_free"
           "__atomic_is_lock_free"))

        (gcc-builtin-functions-sync
         '("__sync_fetch_and_add"
           "__sync_fetch_and_sub"
           "__sync_fetch_and_or"
           "__sync_fetch_and_and"
           "__sync_fetch_and_xor"
           "__sync_fetch_and_nand"
           "__sync_add_and_fetch"
           "__sync_sub_and_fetch"
           "__sync_or_and_fetch"
           "__sync_and_and_fetch"
           "__sync_xor_and_fetch"
           "__sync_nand_and_fetch"
           "__sync_bool_compare_and_swap"
           "__sync_val_compare_and_swap"
           "__sync_synchronize"
           "__sync_lock_test_and_set"
           "__sync_lock_release"))

        (gcc-builtin-functions-ia32
         '("__builtin_ia32_pmovmskb128"
           "__builtin_ia32_pmovmskb256"))

        (gxx-builtin-type-traits
         '("__has_nothrow_assign"
           "__has_trivial_assign"
           "__has_nothrow_copy"
           "__has_trivial_copy"
           "__has_nothrow_constructor"
           "__has_trivial_constructor"
           "__is_pod"
           "__has_trivial_destructor"
           "__has_virtual_destructor"
           "__is_abstract"
           "__is_base_of"
           "__is_class"
           "__is_empty"
           "__is_enum"
           "__is_literal_type"
           "__is_polymorphic"
           "__is_standard_layout"
           "__is_trivial"
           "__is_union"
           "__underlying_type"
           "__integer_pack"
           "__is_same"))

        (cuda-builtin-types
         '("__syncthreads"
           "__shfl"
           "__shfl_xor"
           "__shfl_sync"
           "__shfl_down"
           "__shfl_up_sync"
           "__shfl_down_sync"
           "__shfl_xor_sync"))

        (cosmopolitan-builtin-defines
         '("COSMOPOLITAN_CXX_START_"
           "COSMOPOLITAN_CXX_END_"
           "COSMOPOLITAN_CXX_USING_"
           "COSMOPOLITAN_C_START_"
           "COSMOPOLITAN_C_END_"
           "MACHINE_CODE_ANALYSIS_BEGIN_"
           "MACHINE_CODE_ANALYSIS_END_"
           "__VSCODE_INTELLISENSE__"))

        (cosmopolitan-builtin-functions
         '("DebugBreak"
           "__veil"
           "__conceal"
           "__notice"
           "__expropriate"
           "__yoink"
           "__dll_import"
           "__static_yoink"
           "PYTHON_YOINK"
           "PYTHON_PROVIDE"
           "STATIC_STACK_ADDR"
           "STATIC_STACK_SIZE"
           "STRINGIFY"))

)
    (concat "\\_<"
            (regexp-opt (append c11
                                gcc-cpp-92-builtin-defines
                                gcc-builtin-types
                                gcc-builtin-functions
                                gcc-builtin-functions-atomic
                                gcc-builtin-functions-sync
                                gcc-builtin-functions-ia32
                                gxx-builtin-type-traits
                                cuda-builtin-types
                                cosmopolitan-builtin-defines
                                cosmopolitan-builtin-functions))
            "\\_>")))

(provide 'cosmo-c-builtins)
