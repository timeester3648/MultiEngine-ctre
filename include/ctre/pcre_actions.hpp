#ifndef CTRE__PCRE_ACTIONS__HPP
#define CTRE__PCRE_ACTIONS__HPP

#include "pcre.hpp"
#include "atoms.hpp"
#include <cstdint>
#include <limits>

namespace ctre {
	
template <uint64_t Counter> struct pcre_parameters {
	static constexpr uint64_t current_counter = Counter;
};
	
template <typename Stack = ctll::list<>, typename Parameters = pcre_parameters<0>> struct pcre_context {
	using stack_type = Stack;
	using parameters_type = Parameters;
	static constexpr inline auto stack = stack_type();
	static constexpr inline auto parameters = parameters_type();
	constexpr pcre_context() noexcept { }
	constexpr pcre_context(Stack, Parameters) noexcept { }
};

template <typename... Content, typename Parameters> pcre_context(ctll::list<Content...>, Parameters) -> pcre_context<ctll::list<Content...>, Parameters>;
	
template <uint64_t Value> struct number { };

template <auto...> struct id { };
	
struct pcre_actions {
// i know it's ugly, but it's more readable
#include "actions/characters.inc.hpp"
#include "actions/sequence.inc.hpp"
#include "actions/hexdec.inc.hpp"
#include "actions/options.inc.hpp"
#include "actions/class.inc.hpp"
#include "actions/repeat.inc.hpp"
#include "actions/named_class.inc.hpp"
#include "actions/set.inc.hpp"
#include "actions/asserts.inc.hpp"
#include "actions/capture.inc.hpp"

};


};

#endif