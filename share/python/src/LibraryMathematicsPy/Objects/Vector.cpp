////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/LibraryMathematicsPy/Objects/Vector.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Objects/Vector.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// inline void                     LibraryMathematicsPy_Objects_Vector        	( )
// {

//     using namespace boost::python ;

//     using library::core::mathematics::VectorXd ;

//     class_<VectorXd>("VectorXd", init<int>())

//     // .def(int_(self))

//     // .def(self == self)
//     // .def(self != self)
//     // .def(self < self)
//     // .def(self <= self)
//     // .def(self > self)
//     // .def(self >= self)

//     // .def(self + self)
//     // .def(self += self)
//     // .def(self - self)
//     // .def(self -= self)
//     // .def(self * self)
//     // .def(self *= self)
//     // .def(self / self)
//     // .def(self /= self)

//     // .def(self + int())
//     // .def(self += int())
//     // .def(self - int())
//     // .def(self -= int())
//     // .def(self * int())
//     // .def(self *= int())
//     // .def(self / int())
//     // .def(self /= int())

//     // .def(int() + self)
//     // .def(int() - self)
//     // .def(int() * self)
//     // .def(int() / self)

//     // .def("__str__", +[] (const library::core::types::Integer& anInteger) -> std::string { return anInteger.toString() ; })
//     // .def("__repr__", +[] (const library::core::types::Integer& anInteger) -> std::string { return anInteger.toString() ; })

//     // .def("isDefined", &Integer::isDefined)
//     // .def("isZero", &Integer::isZero)
//     // .def("isPositive", &Integer::isPositive)
//     // .def("isNegative", &Integer::isNegative)
//     // .def("isStrictlyPositive", &Integer::isStrictlyPositive)
//     // .def("isStrictlyNegative", &Integer::isStrictlyNegative)
//     // .def("isInfinity", &Integer::isInfinity)
//     // .def("isPositiveInfinity", &Integer::isPositiveInfinity)
//     // .def("isNegativeInfinity", &Integer::isNegativeInfinity)
//     // .def("isFinite", &Integer::isFinite)
//     // .def("isEven", &Integer::isEven)
//     // .def("isOdd", &Integer::isOdd)

//     // .def("getSign", &Integer::getSign)
//     // .def("toString", &Integer::toString)
    
//     // .def("Undefined", &Integer::Undefined).staticmethod("Undefined")
//     // .def("Zero", &Integer::Zero).staticmethod("Zero")
//     // .def("PositiveInfinity", &Integer::PositiveInfinity).staticmethod("PositiveInfinity")
//     // .def("NegativeInfinity", &Integer::NegativeInfinity).staticmethod("NegativeInfinity")
//     // .def("Int8", &Integer::Int8).staticmethod("Int8")
//     // .def("Int16", &Integer::Int16).staticmethod("Int16")
//     // .def("Int32", &Integer::Int32).staticmethod("Int32")
//     // .def("Int64", &Integer::Int64).staticmethod("Int64")
//     // .def("Uint8", &Integer::Uint8).staticmethod("Uint8")
//     // .def("Uint16", &Integer::Uint16).staticmethod("Uint16")
//     // .def("Uint32", &Integer::Uint32).staticmethod("Uint32")
//     // .def("Uint64", &Integer::Uint64).staticmethod("Uint64")
//     // .def("Index", &Integer::Index).staticmethod("Index")
//     // .def("Size", &Integer::Size).staticmethod("Size")
//     // .def("CanParse", static_cast<bool(*)(const String&)>(&Integer::CanParse)).staticmethod("CanParse")
//     // .def("Parse", static_cast<Integer(*)(const String&)>(&Integer::Parse)).staticmethod("Parse")

//     ;

//     // implicitly_convertible<Integer, int>() ;
//     // implicitly_convertible<int, Integer>() ;

// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////