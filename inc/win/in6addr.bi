#pragma once

#include once "_bsd_types.bi"

union in6_addr_u
	Byte(0 to 15) as u_char
	Word(0 to 7) as u_short
end union

type IN6_ADDR
	u as in6_addr_u
end type

type PIN6_ADDR as IN6_ADDR ptr
type LPIN6_ADDR as IN6_ADDR ptr

#define in_addr6 in6_addr
#define _S6_un u
#define _S6_u8 Byte
#define s6_addr _S6_un._S6_u8
#define s6_bytes u.Byte
#define s6_words u.Word