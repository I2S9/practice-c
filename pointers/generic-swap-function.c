void genericSwap(void *a, void *b, unsigned int sizeMemory)
{
  void * tempMemory = malloc(sizeMemory);
  memcpy(tempMemory, a, sizeMemory);
  memcpy(a, b, sizeMemory);
  memcpy(b, tempMemory, sizeMemory);
  free(tempMemory);
}
