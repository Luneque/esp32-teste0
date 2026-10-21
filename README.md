# esp32-teste0

Firmware base de diagnóstico de hardware e monitoramento (*bring-up*) para microcontroladores **ESP32**, desenvolvido utilizando o framework oficial **ESP-IDF v5.3.2** e **FreeRTOS**.

## 📋 Funcionalidades
- **Auto-diagnóstico no Boot:** Identificação dinâmica do chip, contagem de núcleos de CPU, recursos de rádio (Wi-Fi, Bluetooth Classic, BLE), revisão do silício (ECO3) e tamanho da memória Flash SPI externa (4 MB).
- **Auditoria de Memória:** Leitura de patamar mínimo de heap livre no FreeRTOS.
- **Heartbeat & Telemetria:** Loop periódico (2000 ms) emitindo contador de ciclo e *uptime* em segundos via console serial UART0 (115200 bps, 8N1).

Para detalhes completos de arquitetura, requisitos e casos de teste, consulte o [Documento de Especificação Funcional (FSD.md)](FSD.md).

## 🚀 Como Compilar e Gravar

Requer **ESP-IDF v5.3.2** instalado e configurado no terminal.

### 1. Compilação
```powershell
idf.py build
```

### 2. Gravação (Flash)
Substitua `COMx` pela porta serial da sua placa ESP32 (ex: `COM3`):
```powershell
idf.py -p COMx flash
```

### 3. Monitor Serial
```powershell
idf.py -p COMx monitor
```

*(Para compilar, gravar e abrir o monitor em um único comando: `idf.py -p COMx flash monitor`)*
