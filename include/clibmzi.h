#ifndef CLIBMZI_H
#define CLIBMZI_H
#include <clibmz.h>     /* miniz public interfaces */

typedef struct
{
    tinfl_decompressor m_decomp;
    mz_uint m_dict_ofs, m_dict_avail, m_first_call, m_has_flushed;
    int m_window_bits;
    mz_uint8 m_dict[TINFL_LZ_DICT_SIZE];
    tinfl_status m_last_status;
} inflate_state;

/* Radix sorts tdefl_sym_freq[] array by 16-bit key m_key. Returns ptr to sorted values. */
typedef struct
{
    mz_uint16 m_key, m_sym_index;
} tdefl_sym_freq;

/* Limits canonical Huffman code table's max code size. */
enum
{
    TDEFL_MAX_SUPPORTED_HUFF_CODESIZE = 32
};

#define TDEFL_PUT_BITS(b, l)                                       \
    do                                                             \
    {                                                              \
        mz_uint bits = b;                                          \
        mz_uint len = l;                                           \
        MZ_ASSERT(bits <= ((1U << len) - 1U));                     \
        d->m_bit_buffer |= (bits << d->m_bits_in);                 \
        d->m_bits_in += len;                                       \
        while (d->m_bits_in >= 8)                                  \
        {                                                          \
            if (d->m_pOutput_buf < d->m_pOutput_buf_end)           \
                *d->m_pOutput_buf++ = (mz_uint8)(d->m_bit_buffer); \
            d->m_bit_buffer >>= 8;                                 \
            d->m_bits_in -= 8;                                     \
        }                                                          \
    }                                                              \
    MZ_MACRO_END

#define TDEFL_RLE_PREV_CODE_SIZE()                                                                                       \
    {                                                                                                                    \
        if (rle_repeat_count)                                                                                            \
        {                                                                                                                \
            if (rle_repeat_count < 3)                                                                                    \
            {                                                                                                            \
                d->m_huff_count[2][prev_code_size] = (mz_uint16)(d->m_huff_count[2][prev_code_size] + rle_repeat_count); \
                while (rle_repeat_count--)                                                                               \
                    packed_code_sizes[num_packed_code_sizes++] = prev_code_size;                                         \
            }                                                                                                            \
            else                                                                                                         \
            {                                                                                                            \
                d->m_huff_count[2][16] = (mz_uint16)(d->m_huff_count[2][16] + 1);                                        \
                packed_code_sizes[num_packed_code_sizes++] = 16;                                                         \
                packed_code_sizes[num_packed_code_sizes++] = (mz_uint8)(rle_repeat_count - 3);                           \
            }                                                                                                            \
            rle_repeat_count = 0;                                                                                        \
        }                                                                                                                \
    }

#define TDEFL_RLE_ZERO_CODE_SIZE()                                                         \
    {                                                                                      \
        if (rle_z_count)                                                                   \
        {                                                                                  \
            if (rle_z_count < 3)                                                           \
            {                                                                              \
                d->m_huff_count[2][0] = (mz_uint16)(d->m_huff_count[2][0] + rle_z_count);  \
                while (rle_z_count--)                                                      \
                    packed_code_sizes[num_packed_code_sizes++] = 0;                        \
            }                                                                              \
            else if (rle_z_count <= 10)                                                    \
            {                                                                              \
                d->m_huff_count[2][17] = (mz_uint16)(d->m_huff_count[2][17] + 1);          \
                packed_code_sizes[num_packed_code_sizes++] = 17;                           \
                packed_code_sizes[num_packed_code_sizes++] = (mz_uint8)(rle_z_count - 3);  \
            }                                                                              \
            else                                                                           \
            {                                                                              \
                d->m_huff_count[2][18] = (mz_uint16)(d->m_huff_count[2][18] + 1);          \
                packed_code_sizes[num_packed_code_sizes++] = 18;                           \
                packed_code_sizes[num_packed_code_sizes++] = (mz_uint8)(rle_z_count - 11); \
            }                                                                              \
            rle_z_count = 0;                                                               \
        }                                                                                  \
    }

#define TDEFL_READ_UNALIGNED_WORD32(p) *(const mz_uint32 *)(p)
#define TDEFL_READ_UNALIGNED_WORD(p) *(const mz_uint16 *)(p)
#define TDEFL_READ_UNALIGNED_WORD2(p) *(const mz_uint16 *)(p)

typedef struct
{
    size_t m_size, m_capacity;
    mz_uint8 *m_pBuf;
    mz_bool m_expandable;
} tdefl_output_buffer;

#define TINFL_MEMCPY(d, s, l) memcpy(d, s, l)
#define TINFL_MEMSET(p, c, l) memset(p, c, l)

#define TINFL_CR_BEGIN  \
    switch (r->m_state) \
    {                   \
        case 0:
#define TINFL_CR_RETURN(state_index, result) \
    do                                       \
    {                                        \
        status = result;                     \
        r->m_state = state_index;            \
        goto common_exit;                    \
        case state_index:;                   \
    }                                        \
    MZ_MACRO_END
#define TINFL_CR_RETURN_FOREVER(state_index, result) \
    do                                               \
    {                                                \
        for (;;)                                     \
        {                                            \
            TINFL_CR_RETURN(state_index, result);    \
        }                                            \
    }                                                \
    MZ_MACRO_END
#define TINFL_CR_FINISH }

#define TINFL_GET_BYTE(state_index, c)                                                                                                                           \
    do                                                                                                                                                           \
    {                                                                                                                                                            \
        while (pIn_buf_cur >= pIn_buf_end)                                                                                                                       \
        {                                                                                                                                                        \
            TINFL_CR_RETURN(state_index, (decomp_flags & TINFL_FLAG_HAS_MORE_INPUT) ? TINFL_STATUS_NEEDS_MORE_INPUT : TINFL_STATUS_FAILED_CANNOT_MAKE_PROGRESS); \
        }                                                                                                                                                        \
        c = *pIn_buf_cur++;                                                                                                                                      \
    }                                                                                                                                                            \
    MZ_MACRO_END

#define TINFL_NEED_BITS(state_index, n)                \
    do                                                 \
    {                                                  \
        mz_uint c;                                     \
        TINFL_GET_BYTE(state_index, c);                \
        bit_buf |= (((tinfl_bit_buf_t)c) << num_bits); \
        num_bits += 8;                                 \
    } while (num_bits < (mz_uint)(n))
#define TINFL_SKIP_BITS(state_index, n)      \
    do                                       \
    {                                        \
        if (num_bits < (mz_uint)(n))         \
        {                                    \
            TINFL_NEED_BITS(state_index, n); \
        }                                    \
        bit_buf >>= (n);                     \
        num_bits -= (n);                     \
    }                                        \
    MZ_MACRO_END
#define TINFL_GET_BITS(state_index, b, n)    \
    do                                       \
    {                                        \
        if (num_bits < (mz_uint)(n))         \
        {                                    \
            TINFL_NEED_BITS(state_index, n); \
        }                                    \
        b = bit_buf & ((1 << (n)) - 1);      \
        bit_buf >>= (n);                     \
        num_bits -= (n);                     \
    }                                        \
    MZ_MACRO_END

/* TINFL_HUFF_BITBUF_FILL() is only used rarely, when the number of bytes remaining in the input buffer falls below 2. */
/* It reads just enough bytes from the input stream that are needed to decode the next Huffman code (and absolutely no more). It works by trying to fully decode a */
/* Huffman code by using whatever bits are currently present in the bit buffer. If this fails, it reads another byte, and tries again until it succeeds or until the */
/* bit buffer contains >=15 bits (deflate's max. Huffman code size). */
#define TINFL_HUFF_BITBUF_FILL(state_index, pHuff)                             \
    do                                                                         \
    {                                                                          \
        temp = (pHuff)->m_look_up[bit_buf & (TINFL_FAST_LOOKUP_SIZE - 1)];     \
        if (temp >= 0)                                                         \
        {                                                                      \
            code_len = temp >> 9;                                              \
            if ((code_len) && (num_bits >= code_len))                          \
                break;                                                         \
        }                                                                      \
        else if (num_bits > TINFL_FAST_LOOKUP_BITS)                            \
        {                                                                      \
            code_len = TINFL_FAST_LOOKUP_BITS;                                 \
            do                                                                 \
            {                                                                  \
                temp = (pHuff)->m_tree[~temp + ((bit_buf >> code_len++) & 1)]; \
            } while ((temp < 0) && (num_bits >= (code_len + 1)));              \
            if (temp >= 0)                                                     \
                break;                                                         \
        }                                                                      \
        TINFL_GET_BYTE(state_index, c);                                        \
        bit_buf |= (((tinfl_bit_buf_t)c) << num_bits);                         \
        num_bits += 8;                                                         \
    } while (num_bits < 15);

/* TINFL_HUFF_DECODE() decodes the next Huffman coded symbol. It's more complex than you would initially expect because the zlib API expects the decompressor to never read */
/* beyond the final byte of the deflate stream. (In other words, when this macro wants to read another byte from the input, it REALLY needs another byte in order to fully */
/* decode the next Huffman code.) Handling this properly is particularly important on raw deflate (non-zlib) streams, which aren't followed by a byte aligned adler-32. */
/* The slow path is only executed at the very end of the input buffer. */
/* v1.16: The original macro handled the case at the very end of the passed-in input buffer, but we also need to handle the case where the user passes in 1+zillion bytes */
/* following the deflate data and our non-conservative read-ahead path won't kick in here on this code. This is much trickier. */
#define TINFL_HUFF_DECODE(state_index, sym, pHuff)                                                                                  \
    do                                                                                                                              \
    {                                                                                                                               \
        int temp;                                                                                                                   \
        mz_uint code_len, c;                                                                                                        \
        if (num_bits < 15)                                                                                                          \
        {                                                                                                                           \
            if ((pIn_buf_end - pIn_buf_cur) < 2)                                                                                    \
            {                                                                                                                       \
                TINFL_HUFF_BITBUF_FILL(state_index, pHuff);                                                                         \
            }                                                                                                                       \
            else                                                                                                                    \
            {                                                                                                                       \
                bit_buf |= (((tinfl_bit_buf_t)pIn_buf_cur[0]) << num_bits) | (((tinfl_bit_buf_t)pIn_buf_cur[1]) << (num_bits + 8)); \
                pIn_buf_cur += 2;                                                                                                   \
                num_bits += 16;                                                                                                     \
            }                                                                                                                       \
        }                                                                                                                           \
        if ((temp = (pHuff)->m_look_up[bit_buf & (TINFL_FAST_LOOKUP_SIZE - 1)]) >= 0)                                               \
            code_len = temp >> 9, temp &= 511;                                                                                      \
        else                                                                                                                        \
        {                                                                                                                           \
            code_len = TINFL_FAST_LOOKUP_BITS;                                                                                      \
            do                                                                                                                      \
            {                                                                                                                       \
                temp = (pHuff)->m_tree[~temp + ((bit_buf >> code_len++) & 1)];                                                      \
            } while (temp < 0);                                                                                                     \
        }                                                                                                                           \
        sym = temp;                                                                                                                 \
        bit_buf >>= code_len;                                                                                                       \
        num_bits -= code_len;                                                                                                       \
    }                                                                                                                               \
    MZ_MACRO_END

struct mz_private {
    /* private structures */
    const mz_uint16     *s_tdefl_len_sym;
    const mz_uint8      *s_tdefl_len_extra;
    const mz_uint8      *s_tdefl_small_dist_sym;
    const mz_uint8      *s_tdefl_small_dist_extra;
    const mz_uint8      *s_tdefl_large_dist_sym;
    const mz_uint8      *s_tdefl_large_dist_extra;
    const mz_uint8      *s_tdefl_packed_code_size_syms_swizzle;
    const mz_uint       *mz_bitmasks;
    const mz_uint       *s_tdefl_num_probes;

    /* function pointers */
    tdefl_sym_freq *    (*tdefl_radix_sort_syms)(mz_uint num_syms, tdefl_sym_freq *pSyms0, tdefl_sym_freq *pSyms1);
    void                (*tdefl_calculate_minimum_redundancy)(tdefl_sym_freq *A, int n);
    void                (*tdefl_huffman_enforce_max_code_size)(int *pNum_codes, int code_list_len, int max_code_size);
    void                (*tdefl_optimize_huffman_table)(tdefl_compressor *d, int table_num, int table_len, int code_size_limit, int static_table);
    void                (*tdefl_start_dynamic_block)(tdefl_compressor *d);
    void                (*tdefl_start_static_block)(tdefl_compressor *d);
    mz_bool             (*tdefl_compress_lz_codes)(tdefl_compressor *d);
    mz_bool             (*tdefl_compress_block)(tdefl_compressor *d, mz_bool static_block);
    int                 (*tdefl_flush_block)(tdefl_compressor *d, int flush);
    void                (*tdefl_find_match)(tdefl_compressor *d, mz_uint lookahead_pos, mz_uint max_dist, mz_uint max_match_len, mz_uint *pMatch_dist, mz_uint *pMatch_len);
    mz_bool             (*tdefl_compress_fast)(tdefl_compressor *d);
    void                (*tdefl_record_literal)(tdefl_compressor *d, mz_uint8 lit);
    void                (*tdefl_record_match)(tdefl_compressor *d, mz_uint match_len, mz_uint match_dist);
    mz_bool             (*tdefl_compress_normal)(tdefl_compressor *d);
    tdefl_status        (*tdefl_flush_output_buffer)(tdefl_compressor *d);
    mz_bool             (*tdefl_output_buffer_putter)(const void *pBuf, int len, void *pUser);
};

#ifdef MZ_PRIVATE
extern struct mz_private   *__mzcore;   /* see @@MZCORE.C for implementation */
#define s_tdefl_len_sym                         ((__mzcore->s_tdefl_len_sym))
#define s_tdefl_len_extra                       ((__mzcore->s_tdefl_len_extra))
#define s_tdefl_small_dist_sym                  ((__mzcore->s_tdefl_small_dist_sym))
#define s_tdefl_small_dist_extra                ((__mzcore->s_tdefl_small_dist_extra))
#define s_tdefl_large_dist_sym                  ((__mzcore->s_tdefl_large_dist_sym))
#define s_tdefl_large_dist_extra                ((__mzcore->s_tdefl_large_dist_extra))
#define s_tdefl_packed_code_size_syms_swizzle   ((__mzcore->s_tdefl_packed_code_size_syms_swizzle))
#define mz_bitmasks                             ((__mzcore->mz_bitmasks))
#define s_tdefl_num_probes                      ((__mzcore->s_tdefl_num_probes))

#define tdefl_radix_sort_syms(num_syms,pSyms0,pSyms1)                                       \
    ((__mzcore->tdefl_radix_sort_syms)((num_syms),(pSyms0),(pSyms1)))
#define tdefl_calculate_minimum_redundancy(A,n)                                             \
    ((__mzcore->tdefl_calculate_minimum_redundancy)((A),(n)))
#define tdefl_huffman_enforce_max_code_size(pNum_codes,code_list_len,max_code_size)         \
    ((__mzcore->tdefl_huffman_enforce_max_code_size)((pNum_codes),(code_list_len),(max_code_size)))
#define tdefl_optimize_huffman_table(d,table_num,table_len,code_size_limit,static_table)    \
    ((__mzcore->tdefl_optimize_huffman_table)((d),(table_num),(table_len),(code_size_limit),(static_table)))
#define tdefl_start_dynamic_block(d)                                                        \
    ((__mzcore->tdefl_start_dynamic_block)((d)))
#define tdefl_start_static_block(d)                                                         \
    ((__mzcore->tdefl_start_static_block)((d)))
#define tdefl_compress_lz_codes(d)                                                          \
    ((__mzcore->tdefl_compress_lz_codes)((d)))
#define tdefl_compress_block(d,static_block)                                                \
    ((__mzcore->tdefl_compress_block)((d),(static_block)))
#define tdefl_flush_block(d,flush)                                                          \
    ((__mzcore->tdefl_flush_block)((d),(flush)))
#define tdefl_find_match(d,lookahead_pos,max_dist,max_match_len,pMatch_dist,pMatch_len)     \
    ((__mzcore->tdefl_find_match)((d),(lookahead_pos),(max_dist),(max_match_len),(pMatch_dist),(pMatch_len)))
#define tdefl_compress_fast(d)                                                              \
    ((__mzcore->tdefl_compress_fast)((d)))
#define tdefl_record_literal(d,lit)                                                         \
    ((__mzcore->tdefl_record_literal)((d),(lit)))
#define tdefl_record_match(d,match_len,match_dist)                                          \
    ((__mzcore->tdefl_record_match)((d),(match_len),(match_dist)))
#define tdefl_compress_normal(d)                                                            \
    ((__mzcore->tdefl_compress_normal)((d)))
#define tdefl_flush_output_buffer(d)                                                        \
    ((__mzcore->tdefl_flush_output_buffer)((d)))
#define tdefl_output_buffer_putter(pBuf,len,pUser)                                          \
    ((__mzcore->tdefl_output_buffer_putter)((pBuf),(len),(pUser)))

#endif /* MZ_PRIVATE */

#endif /* CLIBMZI_H */
