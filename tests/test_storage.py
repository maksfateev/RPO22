from pathlib import Path

from src.storage import load_orders, save_orders


def test_save_and_load_orders(tmp_path: Path) -> None:
    file_path = tmp_path / "orders.json"
    orders = [
        {"id": 1, "amount": 100.0},
        {"id": 2, "amount": 250.5},
    ]

    save_orders(str(file_path), orders)
    loaded = load_orders(str(file_path))

    assert loaded == orders
