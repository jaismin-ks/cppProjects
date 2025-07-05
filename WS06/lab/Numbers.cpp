#include "Numbers.h"
#include <fstream>
#include <cstring>

namespace seneca {

   // Counts how many numbers are in the file (number of lines)
   int Numbers::numberCount() const {
      std::ifstream file(m_filename);
      if (!file) return 0;
      int count = 0;
      char ch;
      while (file.get(ch)) {
         if (ch == '\n') count++;
      }
      return count;
   }

   // Loads numbers from the file into m_numbers array
   bool Numbers::load() {
      if (m_numCount <= 0) return false;
      delete[] m_numbers;
      m_numbers = new double[m_numCount];
      std::ifstream file(m_filename);
      if (!file) {
         setEmpty();
         return false;
      }
      int i = 0;
      double val;
      while (i < m_numCount && file >> val) {
         m_numbers[i++] = val;
      }
      if (i != m_numCount) {
         setEmpty();
         return false;
      }
      return true;
   }

   // Saves the numbers back to the file if this object is original
   void Numbers::save() const {
      if (!m_isOriginal || isEmpty()) return;
      std::ofstream file(m_filename);
      if (!file) return;
      for (int i = 0; i < m_numCount; ++i) {
         file << m_numbers[i] << '\n';
      }
   }

   // Destructor: saves and frees dynamic memory
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }

   // Copy constructor: copies the numbers from another object (not original)
   Numbers::Numbers(const Numbers& other) {
      setEmpty();
      m_isOriginal = false;
      if (other.m_numbers && other.m_numCount > 0) {
         m_numCount = other.m_numCount;
         m_numbers = new double[m_numCount];
         for (int i = 0; i < m_numCount; ++i) {
            m_numbers[i] = other.m_numbers[i];
         }
      }
   }

   // Copy assignment operator: assign from another object safely
   Numbers& Numbers::operator=(const Numbers& other) {
      if (this != &other) {
         delete[] m_numbers;
         m_numbers = nullptr;
         m_numCount = 0;
         if (other.m_numbers && other.m_numCount > 0) {
            m_numCount = other.m_numCount;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; ++i) {
               m_numbers[i] = other.m_numbers[i];
            }
         }
      }
      return *this;
   }

   // Adds a number to the list by resizing and sorting the array
   Numbers& Numbers::operator+=(double value) {
      if (isEmpty()) return *this;
      double* temp = new double[m_numCount + 1];
      for (int i = 0; i < m_numCount; ++i) {
         temp[i] = m_numbers[i];
      }
      temp[m_numCount] = value;
      m_numCount++;
      delete[] m_numbers;
      m_numbers = temp;
      sort();
      return *this;
   }

   // Displays the numbers or empty message in a formatted way
   std::ostream& Numbers::display(std::ostream& ostr) const {
      if (isEmpty()) {
         ostr << "Empty list";
         return ostr;
      }
      ostr << "=========================\n";
      if (m_isOriginal && m_filename) {
         ostr << m_filename << "\n";
      } else {
         ostr << "*** COPY ***\n";
      }
      for (int i = 0; i < m_numCount; ++i) {
         ostr.precision(2);
         ostr << std::fixed << m_numbers[i];
         if (i < m_numCount - 1) ostr << ", ";
      }
      ostr << "\n-------------------------\n";
      ostr << "Total of " << m_numCount << " number(s)\n";
      ostr.precision(2);
      ostr << std::fixed;
      ostr << "Largest number:  " << max() << "\n";
      ostr << "Smallest number: " << min() << "\n";
      ostr << "Average:         " << average() << "\n";
      ostr << "=========================";
      return ostr;
   }

   // Outputs the Numbers object using display()
   std::ostream& operator<<(std::ostream& os, const Numbers& N) {
      return N.display(os);
   }

   // Inputs a double and adds it to the Numbers object
   std::istream& operator>>(std::istream& is, Numbers& N) {
      double val;
      if (is >> val) {
         N += val;
      }
      return is;
   }

}
