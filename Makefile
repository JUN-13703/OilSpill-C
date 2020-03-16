.PHONY: clean All

All:
	@echo "----------Building project:[ OilSpill_C - Debug ]----------"
	@cd "OilSpill_C" && "$(MAKE)" -f  "OilSpill_C.mk"
clean:
	@echo "----------Cleaning project:[ OilSpill_C - Debug ]----------"
	@cd "OilSpill_C" && "$(MAKE)" -f  "OilSpill_C.mk" clean
