class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;       // To store the original bookings
    vector<pair<int, int>> overlapBookings; // To store the double bookings

    MyCalendarTwo() {}

    bool book(int start, int end) {
        // First, check if the new booking conflicts with existing double bookings.
        for (const auto& booking : overlapBookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                return false; // Cannot book, as it would cause a triple booking
            }
        }

        // Add this booking as a double booking if it overlaps with any existing bookings.
        for (const auto& booking : bookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                // Get the overlapping interval and store it in the overlapBookings.
                overlapBookings.push_back(getOverlapped(booking.first, booking.second, start, end));
            }
        }

        // Finally, add the new booking to the list of bookings.
        bookings.push_back({start, end});
        return true;
    }

private:
    // Return true if the booking [start1, end1) & [start2, end2) overlap.
    bool doesOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    // Return the overlapping booking between [start1, end1) & [start2, end2).
    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }
};