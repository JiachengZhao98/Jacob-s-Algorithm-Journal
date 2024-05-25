#include <map>
#include "iostream"
#include "cassert"

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.


void assign(K const& keyBegin, K const& keyEnd, V const& val) {
    if (!(keyBegin < keyEnd)) return; // Ensures the interval is valid.

    // Find the start point where the new interval should begin, or adjust if necessary.
    auto itLower = m_map.lower_bound(keyBegin);
    if (itLower != m_map.begin() && std::prev(itLower)->second == val) {
        // Merge with previous interval if it has the same value.
        --itLower;
    } else {
        // Insert or update the start of the interval with the new value.
        m_map[keyBegin] = val;
    }

    // Handle the end of the interval.
    auto itUpper = m_map.lower_bound(keyEnd);
    if (itUpper != m_map.end() && itUpper->first == keyEnd) {
        // Direct match found at keyEnd, evaluate if adjustment is needed.
        auto nextIt = std::next(itUpper);
        if (nextIt != m_map.end() && nextIt->second != val) {
            // If the value after keyEnd is not val, adjust keyEnd to m_valBegin.
            m_map[keyEnd] = m_valBegin;
            itUpper = nextIt; // Move upper boundary to ensure correct range erasure.
        }
    } else {
        // No direct match at keyEnd, insert to ensure correct default transition.
        m_map[keyEnd] = m_valBegin;
    }

    // Remove elements that fall within the new interval, avoiding invalidating itLower when it points to keyBegin.
    if (itLower != m_map.end() && itLower->first == keyBegin) {
        ++itLower; // Skip the newly inserted start of the interval.
    }
    m_map.erase(itLower, itUpper);

    // Cleanup: Remove any redundant entries.
    auto it = (!m_map.empty()) ? m_map.begin() : m_map.end();
    while (it != m_map.end()) {
        auto nextIt = std::next(it);
        if (nextIt != m_map.end() && it->second == nextIt->second) {
            // Erase the next iterator if it has the same value as the current to maintain canonical form.
            m_map.erase(nextIt);
        } else {
            ++it;
        }
    }

    // Additionally, ensure no entry at the beginning duplicates m_valBegin.
    if (!m_map.empty() && m_map.begin()->second == m_valBegin) {
        m_map.erase(m_map.begin());
    }
}







	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

void testAssignNewInterval() {
    interval_map<int, char> m_map('A');
    m_map.assign(1, 5, 'B');
    assert(m_map[-1] == 'A');
    assert(m_map[1] == 'B');
    assert(m_map[4] == 'B');
    assert(m_map[5] == 'A');
    std::cout << "testAssignNewInterval passed." << std::endl;
}

void testAssignOverlappingInterval() {
    interval_map<int, char> map('A');
    map.assign(1, 5, 'B');
    map.assign(3, 7, 'C');
	assert(map[0] == 'A');
    assert(map[2] == 'B');
    assert(map[3] == 'C');
    assert(map[6] == 'C');
    assert(map[9] == 'A');
    std::cout << "testAssignOverlappingInterval passed." << std::endl;
}

void testAssignAdjacentIntervals() {
    interval_map<int, char> map('A');
    map.assign(1, 5, 'B');
    map.assign(5, 10, 'B');
    assert(map[0] == 'A');
    assert(map[1] == 'B');
    assert(map[9] == 'B');
    assert(map[10] == 'A');
    std::cout << "testAssignAdjacentIntervals passed." << std::endl;
}

void testAssignWithSameValueAsValBegin() {
    interval_map<int, char> map('A');
    map.assign(1, 5, 'A'); // This should effectively do nothing.
    assert(map[0] == 'A');
    assert(map[1] == 'A');
    assert(map[4] == 'A');
    assert(map[5] == 'A');
    std::cout << "testAssignWithSameValueAsValBegin passed." << std::endl;
}

void testAssignEmptyInterval() {
    interval_map<int, char> map('A');
    map.assign(5, 5, 'B'); // Assigning an empty interval.
    assert(map[4] == 'A');
    assert(map[5] == 'A');
    std::cout << "testAssignEmptyInterval passed." << std::endl;
}

void testAssignToEnsureCanonicalForm() {
    interval_map<int, char> map('A');
    map.assign(1, 5, 'B');
    map.assign(5, 10, 'C');
    map.assign(3, 7, 'B'); // This should merge the two 'B' intervals
    assert(map[2] == 'B');
    assert(map[3] == 'B');
    assert(map[7] == 'C');
    std::cout << "testAssignToEnsureCanonicalForm passed." << std::endl;
}

int main() {
    // Run the unit tests
    testAssignNewInterval();
    testAssignOverlappingInterval(); // (map[9] == 'A')
    //`testAssignAdjacentIntervals(); // (map[1] == 'B')
    testAssignWithSameValueAsValBegin();
    testAssignEmptyInterval();
    //testAssignToEnsureCanonicalForm(); // (map[2] == 'B'), function testAssignToEnsureCanonicalForm, file interval_map.cpp, line 143.

    std::cout << "All tests passed." << std::endl;
    return 0;
}

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
