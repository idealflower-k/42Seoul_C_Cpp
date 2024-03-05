#include "Serializer.hpp"

int main(void) {
  Data data("sanghwal", 26, 5);
  Data* p_data = &data;

  uintptr_t uint_data = Serializer::serialize(p_data);
  Data* after_dese = Serializer::deserialize(uint_data);
  if (p_data == after_dese) {
    std::cout << "... p_data == after_dese!!... \n";
    std::cout << "p_data: " << p_data << " == afte_dese: " << after_dese
              << "\n\n";
  } else {
    std::cout << "... deserialize error... \n";
    std::cout << "p_data: " << p_data << " != afte_dese: " << after_dese
              << "\n\n";
  }

  uintptr_t after_uint = Serializer::serialize(after_dese);
  if (uint_data == after_uint) {
    std::cout << "... uint_data == after_uint!!... \n";
    std::cout << "uint_data: " << uint_data << " == after_uint: " << after_uint
              << "\n\n";
  } else {
    std::cout << "... Serializer error... \n";
    std::cout << "uint_data: " << uint_data << " != after_uint: " << after_uint
              << "\n\n";
  }

  std::cout << "Data members: [" << data.name << ", " << data.age << ", "
            << data.level << "]\n";
  std::cout << "after_dese members: [" << after_dese->name << ", "
            << after_dese->age << ", " << after_dese->level << "]\n";
  return (0);
}

// int main(void) {
//   Data data("sanghwal", 26, 5);
//   Data* p_data = &data;
//   Data wrong_data("wrong", 1, 1);  // wrong data
//   Data* p_wrong = &wrong_data;     // wrong data

//   uintptr_t uint_data = Serializer::serialize(p_data);
//   Data* after_dese = Serializer::deserialize(uint_data);
//   p_data = p_wrong;  // wrong data
//   if (p_data == after_dese) {
//     std::cout << "... p_data == after_dese!!... \n";
//     std::cout << "p_data: " << p_data << " == afte_dese: " << after_dese
//               << "\n\n";
//   } else {
//     std::cout << "... deserialize error... \n";
//     std::cout << "p_data: " << p_data << " != afte_dese: " << after_dese
//               << "\n\n";
//   }

//   uintptr_t after_uint = Serializer::serialize(p_data);  // wrong data
//   if (uint_data == after_uint) {
//     std::cout << "... uint_data == after_uint!!... \n";
//     std::cout << "uint_data: " << uint_data << " == after_uint: " <<
//     after_uint
//               << "\n\n";
//   } else {
//     std::cout << "... Serializer error... \n";
//     std::cout << "uint_data: " << uint_data << " != after_uint: " <<
//     after_uint
//               << "\n\n";
//   }

//   after_dese = Serializer::deserialize(after_uint);  // wrong data
//   std::cout << "Data members: [" << data.name << ", " << data.age << ", "
//             << data.level << "]\n";
//   std::cout << "after_dese members: [" << after_dese->name << ", "
//             << after_dese->age << ", " << after_dese->level << "]\n";
//   return (0);
// }
