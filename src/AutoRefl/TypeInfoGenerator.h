#pragma once

#include "Meta.h"

namespace Ubpa::USRefl {
	class TypeInfoGenerator {
	public:
		struct Config {
			bool nonNamespaceAttrNameWithoutQuotation{ false };
			bool namespaceAttrNameWithQuotation{ false };
			bool generateOverloadedFunctionsForFunctionWithDefaultValue{ true };
			
			bool isAttrValueToFunction{ false };
			
			bool isInitializerAsAttr{ true };
			std::string_view ns_initializer = "";
			std::string_view name_initializer = "__initializer";
			bool isInitializerToFunction{ true };

			enum class ConstMode {
				Constepxr,
				Const,
				NonConst
			};
			ConstMode attrListConstMode{ ConstMode::Constepxr };
			ConstMode fieldListConstMode{ ConstMode::Constepxr };
		};

		TypeInfoGenerator(Config config = Config{}) : config{ std::move(config) } {}

		std::string Generate(const std::vector<TypeMeta>& typeMetas);
	private:
		Config config;
	};
}
