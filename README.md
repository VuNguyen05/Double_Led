# PlatformIO:

Môn học: Phát triển ứng dụng IoT — Khoa Vật lý, Trường Đại học Khoa học Tự nhiên (HUS)  
Môi trường phát triển: PlatformIO / VS Code  

## Mục đích dự án

Dự án này minh họa cách tổ chức mã nguồn sạch (clean code) và kết hợp linh hoạt giữa Thư viện tự phát triển (User Library) và Thư viện mã nguồn mở (Open-source Library) trên nền tảng PlatformIO:
- Xây dựng thư viện C++ (`LED.h`) quản lý LED theo cơ chế bất đồng bộ `millis()` không gây tắc nghẽn.
- Tích hợp thư viện `OneButton` xử lý dội phím (debounce) và bắt các sự kiện thao tác nút bấm nâng cao (Single Click, Double Click, Long Press).
- Thiết kế logic điều khiển đa thiết bị (2 LED) chỉ với 1 nút bấm duy nhất.

## Yêu cầu & Nguyên lý hoạt động

Dự án sử dụng nút bấm tại chân GPIO 23 để điều khiển hai LED với các quy tắc sau:
1. Nhấn kép (Double Click): Chuyển đổi chế độ điều khiển giữa LED 1 (GPIO 25) và LED 2 (GPIO 5).
2. Nhấn đơn (Single Click): Bật / Tắt (Đảo trạng thái) LED đang được chọn điều khiển.
3. Nhấn giữ (Long Press): Chuyển LED đang được chọn sang chế độ Nhấp nháy liên tục (Blink) với chu kỳ 200ms.
4. Thoát nhấp nháy: Nếu LED đang nhấp nháy, thực hiện Single Click sẽ ngắt nháy và chuyển về trạng thái Bật/Tắt cố định.

