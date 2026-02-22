from __future__ import annotations

import json
from pathlib import Path


def save_orders(path: str, orders: list[dict]) -> None:
    data = {
        "orders": orders,
        "count": len(orders),
    }
    Path(path).write_text(json.dumps(data, ensure_ascii=False), encoding="utf-8")


def load_orders(path: str) -> list[dict]:
    payload = json.loads(Path(path).read_text(encoding="utf-8"))
    return payload.get("orders", [])
