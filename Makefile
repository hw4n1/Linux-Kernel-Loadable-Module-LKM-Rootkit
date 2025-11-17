
MODULE_DIR := module
CLIENT_DIR := client

all: module client

# --- Module Compilation ---
module:
	@echo "Building Kernel Module..."
	$(MAKE) -C $(MODULE_DIR)

# --- Client Compilation ---
client:
	@echo "Building User-Space Client..."
	$(CC) $(CLIENT_DIR)/client.c -o $(CLIENT_DIR)/client_ctrl

# --- Cleanup ---
clean:
	@echo "Cleaning project..."
	$(MAKE) -C $(MODULE_DIR) clean
	rm -f $(CLIENT_DIR)/client_ctrl

.PHONY: all module client clean